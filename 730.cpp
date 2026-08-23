class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#') return 0;

        const int INF = 1e9;
        vector<vector<int>> upMoves(n, vector<int>(m, INF));
        deque<pair<int, int>> dq;

        upMoves[r][c] = 0;
        dq.push_front({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                    mat[nx][ny] == '#') {
                    continue;
                }

                // Moving upward consumes one upward move.
                int cost = (nx == x - 1) ? 1 : 0;

                if (upMoves[nx][ny] > upMoves[x][y] + cost) {
                    upMoves[nx][ny] = upMoves[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (upMoves[i][j] == INF) continue;

                int usedUp = upMoves[i][j];
                int usedDown = usedUp + (i - r);

                if (usedUp <= u && usedDown <= d) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
