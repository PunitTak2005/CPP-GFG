class Solution {
  public:
    int numOfWays(int n, int m) {
        long long MOD = 1e9 + 7;
        long long total_squares = (long long)n * m;
        long long ans = 0;

        // The 8 possible L-shaped moves for a knight
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // Traverse each square of the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long attacking_positions = 0;

                // Check how many valid attacks this square can make
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        attacking_positions++;
                    }
                }

                // Total valid placements for the second knight from this square
                long long non_attacking_positions = total_squares - 1 - attacking_positions;
                
                ans = (ans + non_attacking_positions) % MOD;
            }
        }

        return (int)ans;
    }
};
