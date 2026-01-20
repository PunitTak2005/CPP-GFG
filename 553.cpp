class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }
            int best = -1;
            // upper bound: nums[i] is small (<=1000), so this is fine
            for (int x = 0; x <= p; ++x) {
                if ( (x | (x + 1)) == p ) {
                    best = x;
                    break;              // minimal x found
                }
            }
            ans.push_back(best);
        }

        return ans;
    }
};
