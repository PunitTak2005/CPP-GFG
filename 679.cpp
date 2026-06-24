class Solution {
  public:

    // Function to recursively find the shortest path
    bool solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &ans,
               vector<vector<int>> &dp) {

        int n = mat.size();

        // Check if out of bounds
        if (i >= n || j >= n)
            return false;

        // Check if destination reached
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (mat[i][j] == 0)
            return false;

        // Check if already visited
        if (dp[i][j] != -1)
            return dp[i][j];

        ans[i][j] = 1;

        int jump = mat[i][j];

        // Try shortest jumps first
        for (int step = 1; step <= jump; step++) {

            // Try moving right first
            if (solve(i, j + step, mat, ans, dp))
                return dp[i][j] = 1;

            // Try moving down
            if (solve(i + step, j, mat, ans, dp))
                return dp[i][j] = 1;
        }

        ans[i][j] = 0;

        return dp[i][j] = 0;
    }

    // Main function to find the shortest path in the matrix
    vector<vector<int>> shortestDist(vector<vector<int>> &mat) {

        int n = mat.size();

        // Special case for matrix of size 1
        if (n == 1)
            return {{1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Call recursive function to find shortest path
        if (!solve(0, 0, mat, ans, dp))
            return {{-1}};

        return ans;
    }
};
