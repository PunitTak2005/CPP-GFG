class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1-indexed prefix sums
        vector<vector<int>> row(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                row[i][j] = row[i][j - 1] + grid[i - 1][j - 1];
                col[i][j] = col[i - 1][j] + grid[i - 1][j - 1];
            }
        }

        // Try largest size first
        for (int k = min(m, n); k > 1; --k) {
            for (int r = 0; r + k <= m; ++r) {
                for (int c = 0; c + k <= n; ++c) {
                    if (isMagic(grid, row, col, r, c, k))
                        return k;
                }
            }
        }
        return 1;
    }

private:
    bool isMagic(const vector<vector<int>>& g,
                 const vector<vector<int>>& row,
                 const vector<vector<int>>& col,
                 int r, int c, int k) {

        int r0 = r, c0 = c;
        int r1 = r + k - 1, c1 = c + k - 1;

        // target = first row sum
        int target = row[r0 + 1][c1 + 1] - row[r0 + 1][c0];

        // rows
        for (int i = r0; i <= r1; ++i) {
            int sum = row[i + 1][c1 + 1] - row[i + 1][c0];
            if (sum != target) return false;
        }

        // cols
        for (int j = c0; j <= c1; ++j) {
            int sum = col[r1 + 1][j + 1] - col[r0][j + 1];
            if (sum != target) return false;
        }

        // main diagonal
        int diag1 = 0;
        for (int i = 0; i < k; ++i)
            diag1 += g[r0 + i][c0 + i];
        if (diag1 != target) return false;

        // anti-diagonal
        int diag2 = 0;
        for (int i = 0; i < k; ++i)
            diag2 += g[r0 + i][c1 - i];
        if (diag2 != target) return false;

        return true;
    }
};
