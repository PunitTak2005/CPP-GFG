class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // dp[d][s] = ways to get sum s with d dice
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        dp[0][0] = 1;

        for (int d = 1; d <= n; ++d) {
            for (int s = 1; s <= x; ++s) {
                long long ways = 0;
                for (int face = 1; face <= m; ++face) {
                    if (s - face >= 0)
                        ways += dp[d - 1][s - face];
                }
                dp[d][s] = ways;
            }
        }

        return dp[n][x];
    }
};
