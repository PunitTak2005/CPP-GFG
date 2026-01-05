class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sumAbs = 0;
        int cntNeg = 0;
        long long mn = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long x = matrix[i][j];
                sumAbs += llabs(x);
                if (x < 0) cntNeg++;
                mn = min(mn, llabs(x));
            }
        }

        if (cntNeg % 2 == 0) return sumAbs;
        return sumAbs - 2 * mn;
    }
};
