class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int layers = min(m, n) / 2;  // number of rings
        
        for (int layer = 0; layer < layers; ++layer) {
            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;
            
            // 1) Extract this ring into a vector
            vector<int> ring;
            
            // top row (left -> right)
            for (int j = left; j <= right; ++j)
                ring.push_back(grid[top][j]);
            
            // right column (top+1 -> bottom-1)
            for (int i = top + 1; i <= bottom - 1; ++i)
                ring.push_back(grid[i][right]);
            
            // bottom row (right -> left)
            for (int j = right; j >= left; --j)
                ring.push_back(grid[bottom][j]);
            
            // left column (bottom-1 -> top+1)
            for (int i = bottom - 1; i >= top + 1; --i)
                ring.push_back(grid[i][left]);
            
            int len = ring.size();
            int r = k % len;           // effective rotation
            if (r != 0) {
                // counter-clockwise means shifting left by r
                rotate(ring.begin(), ring.begin() + r, ring.end());
            }
            
            // 2) Put rotated values back into the grid
            int idx = 0;
            
            // top row (left -> right)
            for (int j = left; j <= right; ++j)
                grid[top][j] = ring[idx++];
            
            // right column (top+1 -> bottom-1)
            for (int i = top + 1; i <= bottom - 1; ++i)
                grid[i][right] = ring[idx++];
            
            // bottom row (right -> left)
            for (int j = right; j >= left; --j)
                grid[bottom][j] = ring[idx++];
            
            // left column (bottom-1 -> top+1)
            for (int i = bottom - 1; i >= top + 1; --i)
                grid[i][left] = ring[idx++];
        }
        
        return grid;
    }
};
