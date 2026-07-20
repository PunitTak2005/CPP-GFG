class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        // Reduce k, as shifting by total elements returns to original grid
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Flatten (i, j) to 1D index
                int idx = i * n + j;
                // New index after shifting right by k positions
                int newIdx = (idx + k) % total;
                // Map back to 2D
                int ni = newIdx / n;
                int nj = newIdx % n;
                ans[ni][nj] = grid[i][j];
            }
        }

        return ans;
    }
};
