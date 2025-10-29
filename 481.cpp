class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Helper function for BFS that returns {farthest_node, distance}
        auto bfs = [&](int start) {
            vector<int> dist(V, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farthest = start;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto &nbr : adj[node]) {
                    if (dist[nbr] == -1) {
                        dist[nbr] = dist[node] + 1;
                        q.push(nbr);
                        if (dist[nbr] > dist[farthest])
                            farthest = nbr;
                    }
                }
            }

            return pair<int,int>{farthest, dist[farthest]};
        };

        // Step 1: Find farthest node from any node (say 0)
        auto [node1, _] = bfs(0);

        // Step 2: Find farthest node from node1 (this gives diameter)
        auto [node2, dist] = bfs(node1);

        return dist;
    }
};
