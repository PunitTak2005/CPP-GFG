class Solution {
public:
    int m, n;
    vector<vector<char>> g;
    vector<vector<int>> vis; // 0 = unvisited, 1 = visiting, 2 = done
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int x, int y, int px, int py, char ch) {
        vis[x][y] = 1;
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (g[nx][ny] != ch) continue;

            // ignore the cell we just came from
            if (nx == px && ny == py) continue;

            if (vis[nx][ny] == 1) {
                // we reached a node in current DFS stack => cycle
                return true;
            }
            if (vis[nx][ny] == 0) {
                if (dfs(nx, ny, x, y, ch)) return true;
            }
        }
        vis[x][y] = 2;
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        m = g.size();
        n = g[0].size();
        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] == 0) {
                    if (dfs(i, j, -1, -1, g[i][j])) return true;
                }
            }
        }
        return false;
    }
};
