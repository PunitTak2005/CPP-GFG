class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans;
        
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (mat[i][j] != word[0]) continue;
                
                bool found = false;
                
                for (int d = 0; d < 8 && !found; d++) {
                    int r = i, c = j;
                    int k;
                    
                    for (k = 0; k < word.size(); k++) {
                        if (r < 0 || r >= n || c < 0 || c >= m ||
                            mat[r][c] != word[k]) {
                            break;
                        }
                        r += dr[d];
                        c += dc[d];
                    }
                    
                    if (k == word.size()) {
                        found = true;
                    }
                }
                
                if (found) ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
