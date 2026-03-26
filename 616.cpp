class Solution {
public:
    using ll = long long;
    static constexpr ll INF = (ll)4e18;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> row(m, 0), col(n, 0);
        ll total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ll v = grid[i][j];
                row[i] += v;
                col[j] += v;
                total += v;
            }
        }

        auto can = [&](ll a, ll b, ll bestA, ll bestB) -> bool {
            if (a == b) return true;
            if (bestA != INF && a - bestA == b) return true;
            if (bestB != INF && a == b - bestB) return true;
            return false;
        };

        // 1D column: only horizontal cuts, each part is a vertical chain.
        // In a chain, you can remove only an endpoint without disconnecting.
        if (n == 1) {
            ll top = 0;
            for (int i = 0; i < m - 1; ++i) {
                top += row[i];
                ll bottom = total - top;

                // top rows [0..i], bottom rows [i+1..m-1]
                ll bestTop = INF, bestBottom = INF;
                // top endpoints
                bestTop = min(bestTop, (ll)grid[0][0]);
                bestTop = min(bestTop, (ll)grid[i][0]);
                // bottom endpoints
                bestBottom = min(bestBottom, (ll)grid[i + 1][0]);
                bestBottom = min(bestBottom, (ll)grid[m - 1][0]);

                if (can(top, bottom, bestTop, bestBottom)) return true;
            }
            return false;
        }

        // 1D row: only vertical cuts, each part is a horizontal chain.
        if (m == 1) {
            ll left = 0;
            for (int j = 0; j < n - 1; ++j) {
                left += col[j];
                ll right = total - left;

                // left cols [0..j], right cols [j+1..n-1]
                ll bestLeft = INF, bestRight = INF;
                // left endpoints
                bestLeft = min(bestLeft, (ll)grid[0][0]);
                bestLeft = min(bestLeft, (ll)grid[0][j]);
                // right endpoints
                bestRight = min(bestRight, (ll)grid[0][j + 1]);
                bestRight = min(bestRight, (ll)grid[0][n - 1]);

                if (can(left, right, bestLeft, bestRight)) return true;
            }
            return false;
        }

        // General 2D case — your original idea

        // Horizontal cuts
        {
            ll top = 0;
            for (int i = 0; i < m - 1; ++i) {
                top += row[i];
                ll bottom = total - top;

                ll bestTop = INF;
                for (int j = 0; j < n; ++j)
                    bestTop = min(bestTop, (ll)grid[0][j]);
                for (int j = 0; j < n; ++j)
                    bestTop = min(bestTop, (ll)grid[i][j]);
                for (int r = 0; r <= i; ++r) {
                    bestTop = min(bestTop, (ll)grid[r][0]);
                    if (n > 1) bestTop = min(bestTop, (ll)grid[r][n - 1]);
                }

                ll bestBottom = INF;
                for (int j = 0; j < n; ++j)
                    bestBottom = min(bestBottom, (ll)grid[m - 1][j]);
                for (int j = 0; j < n; ++j)
                    bestBottom = min(bestBottom, (ll)grid[i + 1][j]);
                for (int r = i + 1; r < m; ++r) {
                    bestBottom = min(bestBottom, (ll)grid[r][0]);
                    if (n > 1) bestBottom = min(bestBottom, (ll)grid[r][n - 1]);
                }

                if (can(top, bottom, bestTop, bestBottom)) return true;
            }
        }

        // Vertical cuts
        {
            ll left = 0;
            for (int j = 0; j < n - 1; ++j) {
                left += col[j];
                ll right = total - left;

                ll bestLeft = INF;
                for (int i = 0; i < m; ++i)
                    bestLeft = min(bestLeft, (ll)grid[i][0]);
                for (int i = 0; i < m; ++i)
                    bestLeft = min(bestLeft, (ll)grid[i][j]);
                for (int c = 0; c <= j; ++c) {
                    bestLeft = min(bestLeft, (ll)grid[0][c]);
                    if (m > 1) bestLeft = min(bestLeft, (ll)grid[m - 1][c]);
                }

                ll bestRight = INF;
                for (int i = 0; i < m; ++i)
                    bestRight = min(bestRight, (ll)grid[i][n - 1]);
                for (int i = 0; i < m; ++i)
                    bestRight = min(bestRight, (ll)grid[i][j + 1]);
                for (int c = j + 1; c < n; ++c) {
                    bestRight = min(bestRight, (ll)grid[0][c]);
                    if (m > 1) bestRight = min(bestRight, (ll)grid[m - 1][c]);
                }

                if (can(left, right, bestLeft, bestRight)) return true;
            }
        }

        return false;
    }
};
