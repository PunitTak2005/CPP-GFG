class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0);  // dp[j] = length of LCIS ending at b[j]

        for (int i = 0; i < n; i++) {
            int current = 0;  // best LCIS length so far for smaller elements
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], current + 1);
                }
                if (a[i] > b[j]) {
                    current = max(current, dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
