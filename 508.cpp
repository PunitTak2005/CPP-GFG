class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int components = 0;
        
        function<long long(int,int)> dfs = [&](int u, int parent) {
            long long sum = values[u];
            for (int v : adj[u]) {
                if (v == parent) continue;
                sum += dfs(v, u);
            }
            if (sum % k == 0) {
                components++;
                return 0LL; // cut here
            }
            return sum;
        };
        
        dfs(0, -1);
        return components;
    }
};
