class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.size();
        vector<long long> diff(n + 1, 0);

        for (int r : roll) {
            diff[0]++;
            diff[r]--;
        }

        long long shift = 0;
        for (int i = 0; i < n; i++) {
            shift += diff[i];
            int add = shift % 26;
            s[i] = 'a' + (s[i] - 'a' + add) % 26;
        }

        return s;
    }
};
