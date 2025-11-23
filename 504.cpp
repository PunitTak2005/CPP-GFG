#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // Graph adjacency list: connect stones if they share row or column
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // DFS to count connected components
        vector<bool> visited(n, false);
        int components = 0;
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v : adj[u]) {
                if (!visited[v]) dfs(v);
            }
        };
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i);
            }
        }
        
        return n - components;
    }
};
