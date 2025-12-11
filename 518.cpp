class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Maps to store min and max coordinates for each row and column
        unordered_map<int, int> row_min_y, row_max_y;  // for left/right checks
        unordered_map<int, int> col_min_x, col_max_x;  // for up/down checks
        
        // First pass: collect all min/max for each row and column
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            // Update row bounds (for y-coordinate)
            if (row_min_y.find(x) == row_min_y.end()) {
                row_min_y[x] = y;
                row_max_y[x] = y;
            } else {
                row_min_y[x] = min(row_min_y[x], y);
                row_max_y[x] = max(row_max_y[x], y);
            }
            
            // Update column bounds (for x-coordinate)
            if (col_min_x.find(y) == col_min_x.end()) {
                col_min_x[y] = x;
                col_max_x[y] = x;
            } else {
                col_min_x[y] = min(col_min_x[y], x);
                col_max_x[y] = max(col_max_x[y], x);
            }
        }
        
        // Second pass: check which buildings are covered
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            // Check if building is covered in all 4 directions
            // Left: there's a building with smaller y in same row
            // Right: there's a building with larger y in same row
            // Above: there's a building with smaller x in same column
            // Below: there's a building with larger x in same column
            
            bool has_left = (y > row_min_y[x]);
            bool has_right = (y < row_max_y[x]);
            bool has_above = (x > col_min_x[y]);
            bool has_below = (x < col_max_x[y]);
            
            if (has_left && has_right && has_above && has_below) {
                count++;
            }
        }
        
        return count;
    }
};
