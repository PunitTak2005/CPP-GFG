class Solution {
  public:
    int countWays(int n, int m) {
        const int MOD = 1000000007;

        // dp[i] = number of ways to tile a floor of size i × m
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            // Only horizontal placement is possible
            if (i < m) {
                dp[i] = 1;
            }

            // Either all horizontal or all vertical
            else if (i == m) {
                dp[i] = 2;
            }

            // Place a horizontal strip or a vertical block
            else {
                dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
            }
        }

        return dp[n];
    }
};
