class Solution {
  public:
    bool wifiRange(string s, int x) {
        int n = s.size();
        const int INF = 1000000007;
        vector<int> left(n), right(n);

        int cur = -INF;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cur = i;
            left[i] = cur;
        }

        cur = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') cur = i;
            right[i] = cur;
        }

        for (int i = 0; i < n; i++) {
            int distLeft  = (left[i] == -INF) ? INF : i - left[i];
            int distRight = (right[i] == INF)  ? INF : right[i] - i;
            int d = min(distLeft, distRight);
            if (d > x) return false;
        }
        return true;
    }
};
