class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        vector<long long> dp(n + 2, 0);

        dp[1] = i;

        for (int len = 2; len <= n; len++) {
            // Reach len by inserting one character from len - 1
            dp[len] = dp[len - 1] + i;

            if (len % 2 == 0) {
                // Double len/2
                dp[len] = min(dp[len], dp[len / 2] + c);
            } else {
                // Create len+1 by doubling, then delete one character
                dp[len] = min(dp[len], dp[(len + 1) / 2] + c + d);
            }
        }

        return (int)dp[n];
    }
};
