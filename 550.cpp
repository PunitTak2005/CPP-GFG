class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            long long x1 = bottomLeft[i][0];
            long long y1 = bottomLeft[i][1];
            long long x2 = topRight[i][0];
            long long y2 = topRight[i][1];

            for (int j = i + 1; j < n; ++j) {
                long long x3 = bottomLeft[j][0];
                long long y3 = bottomLeft[j][1];
                long long x4 = topRight[j][0];
                long long y4 = topRight[j][1];

                // intersection rectangle coordinates
                long long L = max(x1, x3);
                long long R = min(x2, x4);
                long long B = max(y1, y3);
                long long T = min(y2, y4);

                long long w = R - L;
                long long h = T - B;

                if (w <= 0 || h <= 0) continue;     // no intersection

                long long side = min(w, h);         // largest square side
                ans = max(ans, side * side);        // area
            }
        }
        return ans;
    }
};
