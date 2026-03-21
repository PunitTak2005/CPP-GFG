class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x;
        int bottom = x + k - 1;  // last row inside the k x k square

        while (top < bottom) {
            // swap row "top" with row "bottom" only in columns [y, y + k)
            for (int j = y; j < y + k; ++j) {
                std::swap(grid[top][j], grid[bottom][j]);
            }
            ++top;
            --bottom;
        }
        return grid;
    }
};
