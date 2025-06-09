class Solution {
  public:
    int countStrings(string &s) {
        int n = s.length();
        vector<int> map(26, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (i - map[s[i] - 'a']);
            map[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (map[i] > 1) {
                ans++;
                break;
            }
        }

        return ans;
    }
};
