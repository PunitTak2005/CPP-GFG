//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    vector<vector<int>> adjList;
    vector<int> parent, visited;
    
    bool DFS(int node) {
        visited[node] = 1;
        
        for(int neighbor : adjList[node]) {
            if(!visited[neighbor]) {
                parent[neighbor] = node;
                if(DFS(neighbor)) return true;
            }
            else if(neighbor != parent[node]) {
                return true;
            }
        }
        
        return false;
    }
    
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        adjList.resize(V);
        parent.resize(V, -1);
        visited.resize(V, 0);
        
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int node = 0; node < V; ++node)
            if(!visited[node] && DFS(node))
                return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
