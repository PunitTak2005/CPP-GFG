class Solution {
  public:
    int countStrings(int n, int k) {
        int MAX = 1001;
        int mod = 1000000007;

        // dp[i][j][0] stores count of binary
        // strings of length i with j consecutive
        // 1's and ending at 0.
        // dp[i][j][1] stores count of binary
        // strings of length i with j consecutive
        // 1's and ending at 1.
        int dp[MAX][MAX][2];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < k + 1; j++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][l] = 0;
                }
            }
        }

        // If n = 1 and k = 0.
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;

        for (int i = 2; i <= n; i++) {

            // number of adjacent 1's can not exceed i-1
            for (int j = 0; j < i; j++) {
                dp[i][j][0] = (dp[i - 1][j][0] % mod + dp[i - 1][j][1] % mod) % mod;
                dp[i][j][1] = dp[i - 1][j][0] % mod;

                if (j - 1 >= 0)
                    dp[i][j][1] = (dp[i][j][1] % mod + dp[i - 1][j - 1][1] % mod) % mod;
            }
        }

        return (dp[n][k][0] % mod + dp[n][k][1] % mod) % mod;
    }
};
