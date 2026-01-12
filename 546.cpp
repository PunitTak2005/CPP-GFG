class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        // Iterate through each pair of consecutive points
        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i + 1][0], y2 = points[i + 1][1];
            
            // Calculate differences
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            
            // Time is the maximum of dx and dy
            // Because we can move diagonally min(dx, dy) times
            // Then move in straight line for remaining |dx - dy| steps
            totalTime += max(dx, dy);
        }
        
        return totalTime;
    }
};
