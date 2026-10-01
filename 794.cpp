class Solution {
public:
    int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        
        // Build graph and in-degree
        for (auto &d : dependencies) {
            int u = d[0], v = d[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        
        // dist[i] = earliest finish time of module i
        vector<long long> dist(n, 0);
        queue<int> q;
        
        // Initialize starting modules
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                dist[i] = duration[i];
                q.push(i);
            }
        }
        
        int processed = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;
            
            for (int v : adj[u]) {
                dist[v] = max(dist[v], dist[u] + (long long)duration[v]);
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Cycle detection
        if (processed != n) return -1;
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dist[i]);
        }
        return (int)ans;
    }
};
