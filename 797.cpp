class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                
                dp[i][j] = max(
                    dp[i][j],
                    1 + dfs(ni, nj, matrix)
                );
            }
        }

        return dp[i][j];
    }

    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        this->n = n;
        this->m = m;

        dp.assign(n, vector<int>(m, -1));

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, dfs(i, j, matrix));
            }
        }

        return answer;
    }
};
