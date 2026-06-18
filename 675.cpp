class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        
        // Traverse each cell in the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Only process if cell is 0
                if(mat[i][j] == 0) {
                    // Check left
                    for(int k = j - 1; k >= 0; k--) {
                        if(mat[i][k] == 1) {
                            ans++;
                            break;
                        }
                    }
                    
                    // Check right
                    for(int k = j + 1; k < m; k++) {
                        if(mat[i][k] == 1) {
                            ans++;
                            break;
                        }
                    }
                    
                    // Check up
                    for(int k = i - 1; k >= 0; k--) {
                        if(mat[k][j] == 1) {
                            ans++;
                            break;
                        }
                    }
                    
                    // Check down
                    for(int k = i + 1; k < n; k++) {
                        if(mat[k][j] == 1) {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
