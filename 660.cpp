
class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Preprocessing: Create a map of element -> sorted list of indices
        unordered_map<int, vector<int>> indexMap;
        
        for (int i = 0; i < arr.size(); i++) {
            indexMap[arr[i]].push_back(i);
        }
        
        vector<int> result;
        
        // Process each query
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int x = query[2];
            
            // If element doesn't exist in array
            if (indexMap.find(x) == indexMap.end()) {
                result.push_back(0);
                continue;
            }
            
            const vector<int>& indices = indexMap[x];
            
            // Find first index >= l (lower_bound)
            auto left = lower_bound(indices.begin(), indices.end(), l);
            
            // Find first index > r (upper_bound)
            auto right = upper_bound(indices.begin(), indices.end(), r);
            
            // Count = distance between left and right
            result.push_back(right - left);
        }
        
        return result;
    }
};
