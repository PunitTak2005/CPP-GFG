class Solution {
  public:
    string URLify(string &s) {
        string res;
        res.reserve(s.size() * 3); // optional optimization

        for (char c : s) {
            if (c == ' ') {
                res += "%20";
            } else {
                res += c;
            }
        }
        return res;
    }
};
