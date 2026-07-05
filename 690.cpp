class Solution {
  public:
    int maxCharGap(string &s) {

        // first[i] stores the first index of character ('a' + i)
        vector<int> first(26, -1);
        int res = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            int ch = s[i] - 'a';

            if (first[ch] == -1) {

                // First time seeing this character
                first[ch] = i;
            } else {

                // Characters between first occurrence and current occurrence
                res = max(res, i - first[ch] - 1);
            }
        }

        return res;
    }
};
