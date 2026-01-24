class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());           // sort ascending
        int n = nums.size();
        int ans = 0;
        int i = 0, j = n - 1;
        
        while (i < j) {                           // pair smallest with largest
            int cur = nums[i] + nums[j];
            ans = max(ans, cur);                  // track max pair sum
            ++i;
            --j;
        }
        
        return ans;
    }
};
