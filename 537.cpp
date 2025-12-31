class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row, m = col;
        int lo = 1, hi = cells.size(), ans = 0;

        auto canCross = [&](int day) {
            vector<vector<int>> grid(n, vector<int>(m, 0));
            for (int i = 0; i < day; ++i) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                grid[r][c] = 1;          // flooded
            }

            queue<pair<int,int>> q;
            vector<vector<int>> vis(n, vector<int>(m, 0));

            // start from all land cells in top row
            for (int j = 0; j < m; ++j) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = 1;
                }
            }

            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1) return true;   // reached bottom

                for (auto &d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (vis[nr][nc] || grid[nr][nc] == 1) continue;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            return false;
        };

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canCross(mid)) {
                ans = mid;
                lo = mid + 1;   // try later day
            } else {
                hi = mid - 1;   // too late, try earlier
            }
        }
        return ans;
    }
};
