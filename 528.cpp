class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // keep[i] == true means strs[i] is already strictly less than strs[i+1]
        vector<bool> decided(n - 1, false);
        int deletions = 0;

        for (int col = 0; col < m; ++col) {
            bool bad = false;

            // Check if this column breaks lexicographic order
            for (int i = 0; i < n - 1; ++i) {
                if (!decided[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                // Must delete this column
                ++deletions;
                continue;
            }

            // This column is kept; update decided relations
            for (int i = 0; i < n - 1; ++i) {
                if (!decided[i] && strs[i][col] < strs[i + 1][col]) {
                    decided[i] = true;
                }
            }
        }

        return deletions;
    }
};
