//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Accepts raw edge list directly
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Convert edge list to adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // Standard Dijkstra's using set
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            int node = it.second;
            int dis = it.first;

            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dis + edgeWeight < dist[adjNode]) {
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
