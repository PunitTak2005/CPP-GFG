class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                total += grid[i][j];                              // [page:1]

        // Total sum must be even for any equal partition.
        if (total % 2 != 0) return false;                        // [page:1]
        long long half = total / 2;

        // Check horizontal cuts: between row r and r+1
        long long pref = 0;
        for (int r = 0; r < m - 1; ++r) {                        // cut must leave non‑empty parts
            for (int j = 0; j < n; ++j)
                pref += grid[r][j];
            if (pref == half) return true;                       // [page:1]
        }

        // Check vertical cuts: between column c and c+1
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                colSum[j] += grid[i][j];

        pref = 0;
        for (int c = 0; c < n - 1; ++c) {                        // cut must leave non‑empty parts
            pref += colSum[c];
            if (pref == half) return true;                       // [page:1]
        }

        return false;
    }
};
