class Solution {
  public:
    int noOfWays(int m, int n, int x) {

        // Initialize dp array with size (x + 1), all values set to 0.
        vector<int> dp(x + 1, 0);

        // Base case: 1 way to get sum 0 (no dice)
        dp[0] = 1;

        // Iterate through each dice (i) from 1 to n
        for (int i = 1; i <= n; i++) {

            // Iterate backwards through all possible sums (j) from x to 1
            for (int j = x; j >= 1; j--) {

                // Reset dp[j] before calculating its new value for the current dice
                dp[j] = 0;

                // Loop through all possible dice outcomes (k)
                for (int k = 1; k <= m && j - k >= 0; k++) {
                    dp[j] += dp[j - k];
                }
            }

            // After each dice iteration, set dp[0] to 0
            dp[0] = 0;
        }

        // Return the number of ways to get sum x using n dice
        return dp[x];
    }
};
