class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap (distance, {x, y})
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        
        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y;  // squared distance
            
            maxHeap.push({dist, {x, y}});
            
            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Collect k closest points
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            ans.push_back({top.second.first, top.second.second});
            maxHeap.pop();
        }
        
        return ans;
    }
};
