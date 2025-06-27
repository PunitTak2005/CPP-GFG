class Solution {
  public:
    int getCount(int n) {
        int ans = 0;
        vector<vector<int>> prev(4, vector<int>(3, 1));
        prev[3][0] = 0;
        prev[3][2] = 0;
        // matrix to store current states
        vector<vector<int>> curr(4, vector<int>(3));

        vector<vector<int>> dir = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    curr[i][j] = 0;

                    // For cell * and #
                    if (i == 3 && (j == 0 || j == 2)) {
                        continue;
                    }

                    // Check for all 5 next cells
                    for (auto d : dir) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) {
                            curr[i][j] += prev[x][y];
                        }
                    }
                }
            }

            // Update previous states
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    prev[i][j] = curr[i][j];
                }
            }
        }
        // Add ans from each cell
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans += prev[i][j];
            }
        }

        return ans;
    }
};
