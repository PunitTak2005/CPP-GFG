class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> ans;
        int total = 1 << n; // 2^n
        for (int i = 0; i < total; i++) {
            int g = i ^ (i >> 1);  // gray code of i [web:4][web:6]
            string s;
            for (int bit = n - 1; bit >= 0; --bit) {
                s.push_back((g & (1 << bit)) ? '1' : '0');
            }
            ans.push_back(s);
        }
        return ans;
    }
};
