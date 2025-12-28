class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int i = 0;          // start from top row
        int j = n - 1;      // start from rightmost column
        int count = 0;
        
        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                // grid[i][j] is negative, so all elements below in this column are negative
                count += (m - i);
                j--;        // move left
            } else {
                // grid[i][j] is non-negative, so move down to find negatives
                i++;
            }
        }
        
        return count;
    }
};
