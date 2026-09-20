class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();
        
        // hor[i][j] = consecutive X's ending at (i, j) from left
        // ver[i][j] = consecutive X's ending at (i, j) from top
        vector<vector<int>> hor(n, vector<int>(n, 0));
        vector<vector<int>> ver(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X') {
                    hor[i][j] = 1 + (j > 0 ? hor[i][j - 1] : 0);
                    ver[i][j] = 1 + (i > 0 ? ver[i - 1][j] : 0);
                }
            }
        }
        
        int ans = 0;
        
        // Treat (i, j) as bottom-right corner of a square
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int possibleSide = min(hor[i][j], ver[i][j]);
                
                while (possibleSide > ans) {
                    int topRow = i - possibleSide + 1;
                    int leftCol = j - possibleSide + 1;
                    
                    // Check top edge and left edge
                    if (hor[topRow][j] >= possibleSide &&
                        ver[i][leftCol] >= possibleSide) {
                        ans = possibleSide;
                        break;
                    }
                    
                    possibleSide--;
                }
            }
        }
        
        return ans;
    }
};
