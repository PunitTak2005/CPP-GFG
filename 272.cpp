//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int  i = 0;
        vector<vector<int>>adj(V);
        vector<int>indeg(V, 0);
        
        for ( int i = 0; i  < edges.size(); i++){
            int  u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            indeg[v]++;
        }
        
        queue<int>q;
        
        for ( int i = 0; i < V; i++){
            if ( indeg[i] == 0) q.push(i);
        }
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            i ++;
            
            for ( auto it : adj[node]){
                indeg[it] --;
                if ( indeg[it] == 0) q.push(it);
            }
        }
        
        if ( i < V) return true;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
