class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        long long total = 0;
        for (int x : arr) total += x;

        // Check if valid partition is possible
        if (total < diff) return 0;
        if ((total + diff) & 1) return 0;

        int target = (total + diff) / 2;

        // Count subsets with sum = target
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int x : arr) {
            for (int s = target; s >= x; --s) {
                dp[s] = (dp[s] + dp[s - x]) % MOD;
            }
        }

        return dp[target];
    }
};
