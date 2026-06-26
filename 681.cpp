class Solution {
  public:
    int countWays(string s1, string s2) {
        const int MOD = 1000000007;
        int n = s1.size(), m = s2.size();
        
        // dp[j] = number of ways to form s2[0..j-1] using processed prefix of s1
        vector<long long> dp(m + 1, 0);
        dp[0] = 1; // empty s2
        
        for (int i = 1; i <= n; i++) {
            // traverse backwards to avoid overwriting dp[j-1] needed for this row
            for (int j = m; j >= 1; j--) {
                if (s1[i-1] == s2[j-1]) {
                    dp[j] = (dp[j] + dp[j-1]) % MOD;
                }
                // else dp[j] stays as from previous i (skip s1[i-1])
            }
        }
        
        return (int)dp[m];
    }
};
