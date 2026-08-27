class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Build consecutive-1 heights ending at this row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) height[j]++;
                else height[j] = 0;
            }

            // Column swaps let us arrange heights in descending order
            vector<int> sortedHeight = height;
            sort(sortedHeight.rbegin(), sortedHeight.rend());

            for (int j = 0; j < m; j++) {
                ans = max(ans, sortedHeight[j] * (j + 1));
            }
        }

        return ans;
    }
};
