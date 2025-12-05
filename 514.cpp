class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int k = costs[0].size();
        if (k == 0) return 0;

        // If only one color and more than one wall -> impossible
        if (k == 1 && n > 1) return -1;

        // DP values for previous row
        vector<int> prev = costs[0];
        
        for (int i = 1; i < n; i++) {
            // Find min1 and min2 from previous row
            int min1 = INT_MAX, min2 = INT_MAX;
            int idx1 = -1;

            for (int c = 0; c < k; c++) {
                if (prev[c] < min1) {
                    min2 = min1;
                    min1 = prev[c];
                    idx1 = c;
                } else if (prev[c] < min2) {
                    min2 = prev[c];
                }
            }

            vector<int> curr(k);

            // Compute current row using min1 and min2
            for (int c = 0; c < k; c++) {
                if (c == idx1)
                    curr[c] = costs[i][c] + min2;  // cannot use same color
                else
                    curr[c] = costs[i][c] + min1;
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
