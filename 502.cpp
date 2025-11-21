class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // If not enough edges to connect all nodes, return -1
        if (edges.size() < V - 1) return -1;
        
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Count connected components using DFS
        vector<bool> visited(V, false);
        int components = 0;
        
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int nei : adj[node]) {
                if (!visited[nei]) dfs(nei);
            }
        };
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;
                dfs(i);
            }
        }
        
        // Minimum operations = components - 1
        return components - 1;
    }
};
