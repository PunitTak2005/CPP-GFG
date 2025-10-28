class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0, l = 0;
        for (int x : nums) {
            if (x != 0) {
                l += x;
            } else if (l * 2 == s) {
                // Both directions are valid
                ans += 2;
            } else if (abs(l * 2 - s) <= 1) {
                // Only one direction is valid
                ++ans;
            }
        }
        return ans;
    }
};
