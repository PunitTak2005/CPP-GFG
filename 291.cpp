//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        const int INF = INT_MAX / 2;
    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // Build graph and dist matrix
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        graph[u][v] = graph[v][u] = min(graph[u][v], w);
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    int minCycle = INF;

    // Floyd-Warshall with cycle tracking
    for (int k = 0; k < V; ++k) {
        // Check for cycles passing through vertex k
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                if (dist[i][j] < INF && graph[i][k] < INF && graph[k][j] < INF) {
                    minCycle = min(minCycle, dist[i][j] + graph[i][k] + graph[k][j]);
                }
            }
        }

        // Standard Floyd-Warshall update
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return (minCycle == INF) ? -1 : minCycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends
