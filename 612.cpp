class Solution {
public:
    bool equalMat(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] != b[i][j]) return false;
        return true;
    }

    void rotate90(vector<vector<int>>& m) {
        int n = m.size();
        // transpose
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(m[i][j], m[j][i]);
        // reverse each row
        for (int i = 0; i < n; ++i)
            reverse(m[i].begin(), m[i].end());
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // check 0, 90, 180, 270 degrees
        for (int k = 0; k < 4; ++k) {
            if (equalMat(mat, target)) return true;
            rotate90(mat);
        }
        return false;
    }
};
