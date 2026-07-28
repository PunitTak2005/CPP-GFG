class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {

        int extra = V;

        // Create adjacency list. Extra nodes
        // are used to split weight 2 edges.
        vector<vector<int>> adj(V + edges.size());

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (wt == 1) {
                // Weight 1 edge remains unchanged.
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                // Convert weight 2 edge into two weight 1 edges:
                // u -- 1 -- newNode -- 1 -- v
                adj[u].push_back(extra);
                adj[extra].push_back(v);

                adj[v].push_back(extra);
                adj[extra].push_back(u);

                extra++;
            }
        }

        // BFS on the transformed unweighted
        // graph gives shortest distance.
        vector<int> dist(extra, -1);

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return dist[node];

            for (int nxt : adj[node]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[node] + 1;
                    q.push(nxt);
                }
            }
        }

        // Destination is not reachable from source.
        return -1;
    }
};
