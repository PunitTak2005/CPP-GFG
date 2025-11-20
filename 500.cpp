class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Initialize self-loops
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Add given transformations
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]); // keep minimum cost if multiple edges
        }

        // Floyd–Warshall for all-pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;

        // Check each position in strings
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue; // already equal

            int u = s[i] - 'a';
            int v = t[i] - 'a';

            int best = INF;
            // Try converting both to some common character
            for (int c = 0; c < 26; c++) {
                if (dist[u][c] < INF && dist[v][c] < INF) {
                    best = min(best, dist[u][c] + dist[v][c]);
                }
            }

            if (best == INF) return -1; // impossible
            totalCost += best;
        }

        return totalCost;
    }
};
