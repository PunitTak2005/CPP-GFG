

class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        int ans = INT_MAX;

        // Collect all unique edges (u < v to avoid duplicates)
        vector<vector<int>> uniqueEdges;
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                if (u < v)
                    uniqueEdges.push_back({u, v});
            }
        }

        for (auto &e : uniqueEdges) {
            int u = e[0], v = e[1];

            vector<int> dist(V, -1);
            queue<int> q;

            // Start BFS from node u
            dist[u] = 0;
            q.push(u);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    // Skip the removed edge (u, v)
                    if ((node == u && nei == v) || (node == v && nei == u))
                        continue;

                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.push(nei);
                    }
                }
            }

            if (dist[v] != -1)
                ans = min(ans, dist[v] + 1);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
