class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int rows = mat.size();
        if (rows == 0)
            return false;
        int columns = mat[0].size();

        // Iterate over all pairs of rows
        for (int i = 0; i < rows; i++) {
            for (int p = i + 1; p < rows; p++) {
                int count = 0;

                // Count columns where both rows have 1
                for (int k = 0; k < columns; k++) {
                    if (mat[i][k] == 1 && mat[p][k] == 1) {
                        count++;
                    }
                }
                // If there are at least two such columns, a rectangle exists
                if (count >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
