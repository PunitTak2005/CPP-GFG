class Solution {
  public:
    vector<string> binstr(int n) {
    vector<string> res;

    for (int i = 0; i < (1 << n); i++) {
        string s;

        // build string from bits of i
        for (int j = n - 1; j >= 0; --j)
            s += ((i >> j) & 1) ? '1' : '0';

        res.push_back(s);
    }
    
    return res;
}
};
