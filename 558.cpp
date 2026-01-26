class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // 1. Sort the array to bring potential pairs together
        sort(arr.begin(), arr.end());
        
        int min_diff = INT_MAX;
        vector<vector<int>> result;
        
        // 2. Find the minimum absolute difference
        for (int i = 0; i < arr.size() - 1; ++i) {
            int current_diff = arr[i+1] - arr[i];
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
        
        // 3. Collect all pairs that have the min_diff
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i+1] - arr[i] == min_diff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        
        return result;
    }
};
