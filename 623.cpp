class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> ans;
        
        // s = i + j is constant on each anti-diagonal
        for (int s = 0; s <= 2 * (n - 1); ++s) {
            // i can range from max(0, s - (n - 1)) to min(n - 1, s)
            int rowStart = max(0, s - (n - 1));
            int rowEnd   = min(n - 1, s);
            
            for (int i = rowStart; i <= rowEnd; ++i) {
                int j = s - i;
                ans.push_back(mat[i][j]);
            }
        }
        
        return ans;
    }
};
