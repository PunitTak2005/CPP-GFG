class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        // Build prefix maximum array
        vector<int> pre_max(n);
        pre_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i - 1], nums[i]);
        }
        
        // Traverse from right to left with suffix minimum
        int suf_min = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            // If there's a cut between i and i+1, use prefix max
            // Otherwise, propagate answer from right
            if (i + 1 < n && pre_max[i] > suf_min) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = pre_max[i];
            }
            
            // Update suffix minimum
            suf_min = min(suf_min, nums[i]);
        }
        
        return ans;
    }
};
