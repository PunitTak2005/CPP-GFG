class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        int n = source.size();

        // 1. Assign IDs to all unique strings
        unordered_map<string, int> id;
        vector<string> all;
        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                int idx = id.size();
                id[s] = idx;
                all.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int m = id.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        for (int i = 0; i < m; i++) dist[i][i] = 0;

        // 2. Build graph
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3. Floyd–Warshall
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // 4. DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // Case 1: characters already match
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Case 2: substring replacements
            for (auto& [s, sid] : id) {
                int len = s.size();
                if (i + len > n) continue;

                if (source.substr(i, len) != s) continue;

                string tsub = target.substr(i, len);
                if (!id.count(tsub)) continue;

                int tid = id[tsub];
                if (dist[sid][tid] < INF) {
                    dp[i + len] = min(dp[i + len], dp[i] + dist[sid][tid]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
