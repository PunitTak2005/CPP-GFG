class Solution {
  public:
    int maxArea(vector<int> &height) {

        // Stores the maximum rectangular area found so far.
        int res = 0;
        int n = height.size();

        // Two pointers representing the selected bars.
        int i = 0, j = n - 1;

        // Try all promising pairs by moving the pointer
        // corresponding to the shorter bar inward.
        while (i < j) {

            // Number of bars between the selected bars.
            int width = j - i - 1;

            if (height[i] < height[j]) {

                // The shorter bar determines the rectangle height.
                res = max(res, width * height[i]);
                i++;
            } else if (height[j] < height[i]) {

                // The shorter bar determines the rectangle height.
                res = max(res, width * height[j]);
                j--;
            } else {

                // Both selected bars have the same height.
                res = max(res, width * height[i]);
                i++;
                j--;
            }
        }

        return res;
    }
};
