class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } 
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

        // Map every litter cell to its bit in mask.
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            litterId[litter[i].first][litter[i].second] = i;
        }

        // bestEnergy[r][c][mask] = highest remaining energy seen here.
        vector<vector<vector<int>>> bestEnergy(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<array<int, 4>> q;
        // {row, col, collectedMask, remainingEnergy}
        q.push({sr, sc, 0, energy});
        bestEnergy[sr][sc][0] = energy;

        int moves = 0;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, remaining] = q.front();
                q.pop();

                if (mask == fullMask) return moves;

                // Cannot make another move with zero energy.
                if (remaining == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int newEnergy = remaining - 1;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << litterId[nr][nc]);
                    }

                    // Reset happens after entering the R cell.
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Same position + collected items with less/equal energy
                    // is always worse, so skip it.
                    if (newEnergy <= bestEnergy[nr][nc][newMask]) continue;

                    bestEnergy[nr][nc][newMask] = newEnergy;
                    q.push({nr, nc, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};
