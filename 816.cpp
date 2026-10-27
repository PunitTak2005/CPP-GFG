class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        
        int prev2 = 0; // dp[i-2]
        int prev1 = 1; // dp[i-1]
        
        for (int i = 2; i <= n; i++) {
            int pairValue = (s[i - 2] != s[i - 1]) ? 4 : 3;
            int curr = max(prev1 + 1, prev2 + pairValue);
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
