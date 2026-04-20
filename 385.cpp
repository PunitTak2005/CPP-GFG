class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        
        // Check from left end
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                ans = max(ans, i - 0);
                break; // further left is only smaller distance
            }
        }
        
        // Check from right end
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, (n - 1) - i);
                break; // further right is only smaller distance
            }
        }
        
        return ans;
    }
};
