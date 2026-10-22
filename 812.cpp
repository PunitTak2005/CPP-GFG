class Solution {
  public:
    int minimumSum(string &s) {
        int n = s.size();
        int h = (n + 1) / 2;   // length of first half (includes middle if odd)

        vector<int> fixed(h, -1);   // -1 means free, otherwise 0..25
        for (int i = 0; i < h; i++) {
            char a = s[i], b = s[n - 1 - i];
            if (a == '?' && b == '?') fixed[i] = -1;
            else if (a == '?') fixed[i] = b - 'a';
            else if (b == '?') fixed[i] = a - 'a';
            else if (a != b) return -1;
            else fixed[i] = a - 'a';
        }

        const long long INF = 1e18;
        vector<long long> dp(26, INF), nd(26);

        for (int c = 0; c < 26; c++)
            if (fixed[0] == -1 || fixed[0] == c)
                dp[c] = 0;

        for (int i = 1; i < h; i++) {
            vector<long long> pre(26), suf(26);

            pre[0] = dp[0];
            for (int p = 1; p < 26; p++)
                pre[p] = min(pre[p - 1], dp[p] - p);

            suf[25] = dp[25] + 25;
            for (int p = 24; p >= 0; p--)
                suf[p] = min(suf[p + 1], dp[p] + p);

            for (int c = 0; c < 26; c++) {
                if (fixed[i] != -1 && fixed[i] != c) {
                    nd[c] = INF;
                    continue;
                }
                nd[c] = min(pre[c] + c, suf[c] - c);
            }
            dp = nd;
        }

        long long ans = *min_element(dp.begin(), dp.end());
        return (int)(2 * ans);
    }
};
