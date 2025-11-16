class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        
        // Initialize dp with individual elements
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }
        
        int ans = dp[0];
        
        // Standard O(N^2) DP
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
