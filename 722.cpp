class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        int n = mat.size(), m = mat[0].size();

        // Build a 1-indexed 2D prefix sum for O(1) rectangle sum queries
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] =
                    prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            int minDist = min({i, j, n - i - 1, m - j - 1});

            // Even the single center cell exceeds k -- no valid square at all
            if (mat[i][j] > k) {
                res.push_back(-1);
                continue;
            }

            // Binary search for the largest radius rad whose square sum stays within k
            int lo = 0, hi = minDist, best = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int r1 = i - mid, c1 = j - mid, r2 = i + mid, c2 = j + mid;
                int sum = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] -
                          prefix[r2 + 1][c1] + prefix[r1][c1];

                if (sum <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            res.push_back(2 * best + 1);
        }
        return res;
    }
};
