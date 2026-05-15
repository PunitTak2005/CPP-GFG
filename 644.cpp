class Solution {
public:
    int optimalKeys(int n) {
        if (n <= 0) return 0;
        // dp[i] = max number of 'A's with exactly i key presses
        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            // Option 1: press 'A'
            dp[i] = dp[i - 1] + 1;

            // Option 2: use Ctrl+A, Ctrl+C, then multiple Ctrl+V
            // b = breakpoint where we finish typing/previous operations,
            // then do Ctrl+A, Ctrl+C, and the rest are Ctrl+V
            for (int b = 1; b <= i - 3; ++b) {
                int remaining = i - b;              // keys after position b
                int pastes = remaining - 2;         // Ctrl+A, Ctrl+C take 2
                long long curr = dp[b] * (pastes + 1); // original + pastes
                dp[i] = max(dp[i], curr);
            }
        }

        return (int)dp[n];
    }
};
