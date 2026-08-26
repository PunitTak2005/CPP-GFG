class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1') ones++;

                if (ones > k) break;

                if (ones == k) {
                    string curr = s.substr(i, j - i + 1);

                    if (ans.empty() ||
                        curr.size() < ans.size() ||
                        (curr.size() == ans.size() && curr < ans)) {
                        ans = curr;
                    }

                    // Extending further only adds zeroes, so it cannot be shorter.
                    break;
                }
            }
        }

        return ans;
    }
};
