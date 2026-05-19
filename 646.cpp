class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // If start and end are already the same
        if (start == end) return 0;
        
        // Array to store the minimum steps to reach each number from 0 to 999
        // Initialized with -1 to indicate unvisited states
        vector<int> dist(1000, -1);
        
        queue<int> q;
        
        // Push the starting numbers
        q.push(start);
        dist[start] = 0;
        
        int mod = 1000;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Multiply the current node with every element in the array
            for (int factor : arr) {
                int next_node = (1LL * node * factor) % mod;
                
                // If this state hasn't been visited yet
                if (dist[next_node] == -1) {
                    dist[next_node] = dist[node] + 1;
                    
                    // If we reached the end, return the total steps
                    if (next_node == end) {
                        return dist[next_node];
                    }
                    
                    q.push(next_node);
                }
            }
        }
        
        // If end is unreachable
        return -1;
    }
};
