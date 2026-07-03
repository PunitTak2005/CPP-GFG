class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int M = 26;

        // Fill positions of each character in vector
        vector<int> position[M];

        for (int i = 1; i <= n2; i++)
            position[s2[i - 1] - 'a'].push_back(i);

        int lcsl[n1 + 2][n2 + 2];
        int lcsr[n1 + 2][n2 + 2];

        // Initializing 2D array by 0 values
        for (int i = 0; i <= n1 + 1; i++) {
            for (int j = 0; j <= n2 + 1; j++) {
                lcsl[i][j] = 0;
                lcsr[i][j] = 0;
            }
        }

        // Filling LCS array for prefix substrings
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    lcsl[i][j] = 1 + lcsl[i - 1][j - 1];
                else
                    lcsl[i][j] = max(lcsl[i - 1][j], lcsl[i][j - 1]);
            }
        }

        // Filling LCS array for suffix substrings
        for (int i = n1; i >= 1; i--) {
            for (int j = n2; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1])
                    lcsr[i][j] = 1 + lcsr[i + 1][j + 1];
                else
                    lcsr[i][j] = max(lcsr[i + 1][j], lcsr[i][j + 1]);
            }
        }

        // Looping for all possible insertion positions
        // in first string
        int ways = 0;

        for (int i = 0; i <= n1; i++) {

            // Trying all possible lower case characters
            for (char c = 'a'; c <= 'z'; c++) {

                // Now for each character, loop over same
                // character positions in second string
                for (int j = 0; j < position[c - 'a'].size(); j++) {
                    int p = position[c - 'a'][j];

                    // If both, left and right substrings make
                    // total LCS then increase result by 1
                    if (lcsl[i][p - 1] + lcsr[i + 1][p + 1] == lcsl[n1][n2]) {
                        ways++;
                        break;
                    }
                }
            }
        }

        return ways;
    }
};
