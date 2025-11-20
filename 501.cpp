#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> dijkstra(int V, int src, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(V, 1e15);
        dist[src] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            
            for(auto &edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // adjacency list for straight edges
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges) {
            int u = e[0], v = e[1], w1 = e[2];
            adj[u].push_back({v, w1});
            adj[v].push_back({u, w1});
        }
        
        // run dijkstra from a and b
        vector<long long> distA = dijkstra(V, a, adj);
        vector<long long> distB = dijkstra(V, b, adj);
        
        long long ans = distA[b]; // straight path only
        
        // try using one curved edge
        for(auto &e : edges) {
            int u = e[0], v = e[1], w2 = e[3];
            if(distA[u] != 1e15 && distB[v] != 1e15)
                ans = min(ans, distA[u] + w2 + distB[v]);
            if(distA[v] != 1e15 && distB[u] != 1e15)
                ans = min(ans, distA[v] + w2 + distB[u]);
        }
        
        return (ans >= 1e15 ? -1 : (int)ans);
    }
};
