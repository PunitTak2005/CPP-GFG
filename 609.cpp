class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // prefix for (X=1, Y=-1, .=0)
        vector<vector<int>> pref(n, vector<int>(m, 0));
        // prefix for count of X
        vector<vector<int>> prefX(n, vector<int>(m, 0));
        
        auto val = [&](char c) -> int {
            if (c == 'X') return 1;
            if (c == 'Y') return -1;
            return 0;
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = val(grid[i][j]);
                int isX = (grid[i][j] == 'X');
                
                pref[i][j] = v;
                prefX[i][j] = isX;
                
                if (i > 0) {
                    pref[i][j] += pref[i-1][j];
                    prefX[i][j] += prefX[i-1][j];
                }
                if (j > 0) {
                    pref[i][j] += pref[i][j-1];
                    prefX[i][j] += prefX[i][j-1];
                }
                if (i > 0 && j > 0) {
                    pref[i][j] -= pref[i-1][j-1];
                    prefX[i][j] -= prefX[i-1][j-1];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pref[i][j] == 0 && prefX[i][j] > 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
