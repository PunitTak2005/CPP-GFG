class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Effective shift is k modulo n, since shifting n times returns row to original
        int shift = k % n;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int nj;
                if (i % 2 == 0) {
                    // even row: shift left by 'shift'
                    nj = (j + shift) % n;
                } else {
                    // odd row: shift right by 'shift'
                    nj = (j - shift + n) % n;
                }
                if (mat[i][j] != mat[i][nj]) return false;
            }
        }
        return true;
    }
};
