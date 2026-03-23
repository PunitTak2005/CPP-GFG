class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list from 2D edges array
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0), dist(V, -1);
        int ans = -1;

        function<int(int)> dfs = [&](int node) {
            vis[node] = 1;
            int best = -1;
            for (int nb : adj[node]) {
                if (!vis[nb]) {
                    dist[nb] = dist[node] + 1;
                    best = max(best, dfs(nb));
                } else if (dist[nb] != -1) {
                    best = max(best, dist[node] - dist[nb] + 1);
                }
            }
            dist[node] = -1;
            return best;
        };

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dist[i] = 0;
                ans = max(ans, dfs(i));
            }
        }
        return ans;
    }
};
