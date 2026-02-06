class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {   // <- name must match
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ansKeep = 0;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (j < n && 1LL * nums[j] <= 1LL * k * nums[i]) {
                ++j;
            }
            ansKeep = max(ansKeep, j - i);
        }

        return n - ansKeep;
    }
};
