class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto &e : roads) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // BFS/DFS from node 1 to find its connected component
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        // Minimum edge distance within this component
        int ans = INT_MAX;
        for (auto &e : roads) {
            int a = e[0], b = e[1], d = e[2];
            // If either endpoint is reachable from 1, edge is in the component
            if (vis[a] || vis[b]) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};
