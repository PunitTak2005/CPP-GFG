#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Build adjacency list: for each edge add two directions
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            // original edge
            graph[u].push_back({v, w});
            // reversed edge with doubled cost
            graph[v].push_back({u, 2 * w});
        }
        
        // Dijkstra
        const long long INF = LLONG_MAX / 2;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        
        // Min-heap storing (currentCost, node)
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [curCost, u] = pq.top();
            pq.pop();
            
            if (curCost > dist[u]) continue;
            
            for (auto &nx : graph[u]) {
                int v = nx.first;
                long long cost = nx.second;
                
                if (dist[v] > curCost + cost) {
                    dist[v] = curCost + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};