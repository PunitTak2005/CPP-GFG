class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> merged;
        
        // Step 2: Traverse intervals
        for (auto interval : arr) {
            // If merged is empty OR no overlap, add interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlap → merge by updating the end
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
