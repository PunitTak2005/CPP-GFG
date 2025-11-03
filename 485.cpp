class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Step 1: Build the reversed graph
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            revGraph[v].push_back(u); // reverse the edge
            indegree[u]++;
        }
        
        // Step 2: Kahn's algorithm - start with nodes having 0 indegree
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> safe(V, false);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            
            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Collect all safe nodes
        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        
        sort(result.begin(), result.end()); // optional, for ordered output
        return result;
    }
};
