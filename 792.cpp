class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If path length is odd, impossible to have valid parentheses
        if ((m + n - 1) % 2 == 1) {
            return false;
        }
        
        // Memoization: visited[row][col][balance]
        // balance can range from 0 to (m+n)/2
        int maxBalance = (m + n) / 2;
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(maxBalance + 1, 0)));
        
        return dfs(grid, 0, 0, 0, visited, m, n, maxBalance);
    }
    
private:
    bool dfs(vector<vector<char>>& grid, int row, int col, int balance, 
             vector<vector<vector<int>>>& visited, int m, int n, int maxBalance) {
        
        // Out of bounds
        if (row >= m || col >= n) {
            return false;
        }
        
        // Update balance based on current cell
        if (grid[row][col] == '(') {
            balance++;
        } else {
            balance--;
        }
        
        // Balance went negative - invalid path
        if (balance < 0) {
            return false;
        }
        
        // Balance exceeds maximum possible - can't close all brackets
        if (balance > maxBalance) {
            return false;
        }
        
        // Reached destination
        if (row == m - 1 && col == n - 1) {
            return balance == 0;
        }
        
        // Already visited this state
        if (visited[row][col][balance]) {
            return false;
        }
        
        // Mark as visited
        visited[row][col][balance] = 1;
        
        // Try moving right and down
        return dfs(grid, row, col + 1, balance, visited, m, n, maxBalance) ||
               dfs(grid, row + 1, col, balance, visited, m, n, maxBalance);
    }
};
