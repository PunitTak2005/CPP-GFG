class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // 2D prefix sum with 1-based indexing: ps[i][j] = sum of mat[0..i-1][0..j-1]
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                ps[i][j] = mat[i - 1][j - 1]
                         + ps[i - 1][j]
                         + ps[i][j - 1]
                         - ps[i - 1][j - 1];
            }
        }

        auto squareSum = [&](int x1, int y1, int x2, int y2) {
            // all indices are 1-based and inclusive
            return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
        };

        int low = 0, high = min(m, n), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;  // candidate side length
            bool ok = false;

            if (mid == 0) {
                ok = true;
            } else {
                for (int i = mid; i <= m && !ok; ++i) {
                    for (int j = mid; j <= n && !ok; ++j) {
                        if (squareSum(i - mid + 1, j - mid + 1, i, j) <= threshold) {
                            ok = true;
                        }
                    }
                }
            }

            if (ok) {
                ans = mid;
                low = mid + 1;   // try larger side
            } else {
                high = mid - 1;  // try smaller side
            }
        }

        return ans;
    }
};
