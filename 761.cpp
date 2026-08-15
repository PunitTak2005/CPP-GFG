class Solution {
public:
    string s;
    int forbidden;
    long long dp[12][2][2];

    long long solve(int pos, int tight, int started) {
        if (pos == (int)s.size()) {
            return started ? 1 : 0;
        }

        long long &ans = dp[pos][tight][started];
        if (ans != -1) return ans;

        ans = 0;
        int limit = tight ? (s[pos] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {
            int nextTight = tight && (digit == limit);
            int nextStarted = started || (digit != 0);

            // Ignore leading zeroes; otherwise digit d is forbidden
            if (nextStarted && digit == forbidden) continue;

            ans += solve(pos + 1, nextTight, nextStarted);
        }

        return ans;
    }

    int countWithout(int n, int d) {
        s = to_string(n);
        forbidden = d;

        memset(dp, -1, sizeof(dp));
        return (int)solve(0, 1, 0);
    }
};
