class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<bool> dp(x + 1, false);
        dp[0] = true;

        long long current = s;

        for (int i = 0; i <= arr.size(); i++) {
            if (current > x) break;

            int value = (int)current;

            // 0/1 knapsack: iterate backwards
            for (int sum = x; sum >= value; sum--) {
                dp[sum] = dp[sum] || dp[sum - value];
            }

            if (i < arr.size()) {
                current = 2 * current + arr[i];
            }
        }

        return dp[x];
    }
};
