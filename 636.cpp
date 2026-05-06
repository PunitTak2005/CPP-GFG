class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // 1. Let stones "fall" to the right in each row
        for (int i = 0; i < m; ++i) {
            int emptyPos = n - 1;  // position where next stone can fall
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // obstacle: reset emptyPos just left of it
                    emptyPos = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // stone: move it as far right as possible
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptyPos] = '#';
                    emptyPos--;
                }
                // if '.', just continue
            }
        }

        // 2. Rotate 90 degrees clockwise: result is n x m
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};
