class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prevRun = 0;     // length of previous group of same chars
        int currRun = 1;     // length of current group
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                currRun++;
            } else {
                // when the char changes, we know one full run ended
                ans += min(prevRun, currRun);
                prevRun = currRun;
                currRun = 1;
            }
        }
        // account for the last run
        ans += min(prevRun, currRun);

        return ans;
    }
};
