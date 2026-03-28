class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 0);

        // Basic sanity: diagonal must be lcp[i][i] == n - i
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] != n - i) return "";
        }

        // Step 1: construct lexicographically smallest string consistent with lcp
        char cur = 'a';
        for (int i = 0; i < n; ++i) {
            if (s[i] == 0) {
                if (cur > 'z') return "";         // need more than 26 letters
                s[i] = cur++;
            }
            // For any j > i with lcp[i][j] > 0, s[j] must equal s[i]
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    if (s[j] == 0) s[j] = s[i];
                    else if (s[j] != s[i]) return "";
                }
            }
        }

        // Step 2: recompute LCP of s and verify equals given matrix
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
                else dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return s;
    }
};
