class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;
        
        // Impossible cases
        if (target > total || target < -total) return 0;
        if ((total + target) % 2 != 0) return 0;
        
        int S = (total + target) / 2;
        if (S < 0) return 0;
        
        vector<long long> dp(S + 1, 0);
        dp[0] = 1;  // one way to make sum 0: take nothing
        
        for (int num : arr) {
            for (int s = S; s >= num; --s) {
                dp[s] += dp[s - num];
            }
        }
        return (int)dp[S];
    }
};
