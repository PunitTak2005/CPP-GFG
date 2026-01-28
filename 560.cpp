class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        int maxVal = 0;
        for (auto &row : grid)
            for (int v : row)
                maxVal = max(maxVal, v);

        // dp[t][i][j]: min cost to (i,j) using t teleports
        vector<vector<vector<int>>> dp(k+1,
            vector<vector<int>>(m, vector<int>(n, INF)));

        dp[0][0][0] = 0;  // start at (0,0) cost 0

        // Without teleports: simple DP for right/down
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][j] + grid[i][j]);
                if (j > 0)
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i][j-1] + grid[i][j]);
            }
        }

        // Teleportation layers
        for (int t = 1; t <= k; t++) {
            // Build suffix minimum array of previous dp layer
            vector<int> sufMin(maxVal + 2, INF);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    sufMin[val] = min(sufMin[val], dp[t-1][i][j]);
                }
            }
            for (int val = maxVal; val >= 0; val--) {
                sufMin[val] = min(sufMin[val], sufMin[val+1]);
            }

            // Now fill dp[t]
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // Teleport into (i,j) if possible
                    dp[t][i][j] = min(dp[t][i][j], sufMin[grid[i][j]]);

                    // Normal move transitions
                    if (i > 0)
                        dp[t][i][j] = min(dp[t][i][j], dp[t][i-1][j] + grid[i][j]);
                    if (j > 0)
                        dp[t][i][j] = min(dp[t][i][j], dp[t][i][j-1] + grid[i][j]);
                }
            }
        }

        return dp[k][m-1][n-1];
    }
};