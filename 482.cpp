class Solution {
  public:

    // A recursive function to replace previous value at  '(x, y)'
    // and all surrounding values of (x, y) with new value
    void fillUtil(vector<vector<char>>& grid, int x, int y, char prevV, char newV) {
        int m = grid.size();
        int n = grid[0].size();

        // Base cases
        if (x < 0 || x >= m || y < 0 || y >= n)
            return;
        if (grid[x][y] != prevV)
            return;

        // Replace current cell
        grid[x][y] = newV;

        // Recur for 4 directions
        fillUtil(grid, x + 1, y, prevV, newV);
        fillUtil(grid, x - 1, y, prevV, newV);
        fillUtil(grid, x, y + 1, prevV, newV);
        fillUtil(grid, x, y - 1, prevV, newV);
    }

    void fill(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Replace all 'O' with '-'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O') {
                    grid[i][j] = '-';
                }
            }
        }

        // Flood fill for '-' on edges
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == '-')
                fillUtil(grid, i, 0, '-', 'O');
            if (grid[i][n - 1] == '-')
                fillUtil(grid, i, n - 1, '-', 'O');
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == '-')
                fillUtil(grid, 0, j, '-', 'O');
            if (grid[m - 1][j] == '-')
                fillUtil(grid, m - 1, j, '-', 'O');
        }

        // Replace remaining '-' with 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '-') {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
