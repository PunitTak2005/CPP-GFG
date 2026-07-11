class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             int& nodes, int& edgesCount) {
        vis[node] = 1;
        nodes++;

        for (int nei : adj[node]) {
            edgesCount++;
            if (!vis[nei]) {
                dfs(nei, adj, vis, nodes, edgesCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, edgesCount = 0;
                dfs(i, adj, vis, nodes, edgesCount);

                edgesCount /= 2;  // each undirected edge counted twice
                if (edgesCount == nodes * (nodes - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
