class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat,
                            vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        int q = queries.size();

        // 2D prefix sum (long long to avoid overflow)
        vector<vector<long long>> pre(n, vector<long long>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long up   = (i > 0) ? pre[i-1][j] : 0;
                long long left = (j > 0) ? pre[i][j-1] : 0;
                long long diag = (i > 0 && j > 0) ? pre[i-1][j-1] : 0;
                pre[i][j] = mat[i][j] + up + left - diag;
            }
        }

        vector<int> ans(q);
        for (int k = 0; k < q; ++k) {
            int r1 = queries[k][0];
            int c1 = queries[k][1];
            int r2 = queries[k][2];
            int c2 = queries[k][3];

            long long sum = pre[r2][c2];
            if (r1 > 0)      sum -= pre[r1-1][c2];
            if (c1 > 0)      sum -= pre[r2][c1-1];
            if (r1 > 0 && c1 > 0) sum += pre[r1-1][c1-1];

            ans[k] = (int)sum;   // fits in int under given constraints
        }
        return ans;
    }
};
