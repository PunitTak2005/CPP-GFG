//Back-end complete function Template for C++

class Solution {
  public:
    string maxSubseq(string s, int k) {

        int n = s.length();
        string res = "";
        int rem = n - k;

        // For every character, remove the characters from stack
        // that are smaller than this and we have enough remaining
        // characters in the string
        for (int i = 0; i < n; i++) {
            while (!res.empty() && k > 0 && res.back() < s[i]) {
                res.pop_back();
                k--;
            }

            res.push_back(s[i]);
        }

        while (k > 0) {
            res.pop_back();
            k--;
        }
        return res;
    }
};
