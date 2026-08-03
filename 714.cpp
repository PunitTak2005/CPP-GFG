#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] = maximum score difference (current player - other player)
        // starting from index i.
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0; // no stones left → difference is 0

        for (int i = n - 1; i >= 0; --i) {
            int sum = 0;
            // try taking 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; ++k) {
                sum += stoneValue[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
