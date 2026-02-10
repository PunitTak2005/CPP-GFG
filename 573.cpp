class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> vis;    // distinct values in current subarray
            int cnt[2] = {0, 0};       // cnt[0] = distinct evens, cnt[1] = distinct odds

            for (int j = i; j < n; ++j) {
                if (!vis.contains(nums[j])) {         // first time we see this value
                    vis.insert(nums[j]);
                    ++cnt[nums[j] & 1];               // parity: 0 = even, 1 = odd
                }

                if (cnt[0] == cnt[1]) {
                    ans = max(ans, j - i + 1);        // update longest balanced length
                }
            }
        }

        return ans;
    }
};
