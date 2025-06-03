class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Length of first string
        int n1 = s1.length();
        // Length of second string
        int n2 = s2.length();
        // Length of third string
        int n3 = s3.length();

        // Initialize two 2D arrays for DP:
        // prev holds values for previous i-1 level
        // curr holds values for current i level
        vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));

        // Iterate over all characters of s1
        for (int i = 1; i <= n1; i++) {

            // Iterate over all characters of s2
            for (int j = 1; j <= n2; j++) {

                // Iterate over all characters of s3
                for (int k = 1; k <= n3; k++) {

                    // If current characters of all three strings match
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    else
                        // Take the maximum of excluding current
                        // character from any one string
                        curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
                }
            }
            // Move curr to prev for the next iteration
            prev = curr;
        }

        // The result is in curr[n2][n3], which holds the final LCS length
        return curr[n2][n3];
    }
};
