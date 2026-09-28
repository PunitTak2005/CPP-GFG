class Solution {
public:
    int maxDepth(string s) {
        int curr = 0, ans = 0;
        for (char c : s) {
            if (c == '(') {
                curr++;
                ans = max(ans, curr);
            } else if (c == ')') {
                curr--;
            }
        }
        return ans;
    }
};
