//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>ans;
    
    
    
    void dfsUtil(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=1;
        ans.push_back(node);
        for(int &ngbr:adj[node]){
            if(!visited[ngbr]){
                dfsUtil(ngbr,adj,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
       
        int n=adj.size();
        vector<int>visited(n,0);
        dfsUtil(0,adj,visited);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
