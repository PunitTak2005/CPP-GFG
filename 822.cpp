class Solution {
public:
    int getMinimumDays(string &s, vector<int> &p) {
        int n = s.size();
        vector<int> day(n);
        
        for (int i = 0; i < n; i++) {
            day[p[i]] = i;   // position p[i] becomes '?' on day i (0-based)
        }
        
        int ans = 0;
        
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                // Earliest day one of these two positions is removed
                ans = max(ans, min(day[i], day[i + 1]) + 1);
            }
        }
        
        return ans;
    }
};
