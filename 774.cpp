class Solution {
public:
    int countSubsequences(string &s, int n) {
        const int MOD = 1e9 + 7;
        
        vector<long long> dp(n, 0);
        
        for (char ch : s) {
            int digit = ch - '0';
            
            // Subsequences that skip this digit remain unchanged
            vector<long long> ndp = dp;
            
            // Start a new subsequence containing only this digit
            ndp[digit % n] = (ndp[digit % n] + 1) % MOD;
            
            // Append this digit to all already formed subsequences
            for (int rem = 0; rem < n; rem++) {
                int newRem = (rem * 10 + digit) % n;
                ndp[newRem] = (ndp[newRem] + dp[rem]) % MOD;
            }
            
            dp = ndp;
        }
        
        return dp[0];
    }
};
