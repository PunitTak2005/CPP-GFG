class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;

        // dp0[i][j] = #ways with i zeros, j ones, last bit = 0
        // dp1[i][j] = #ways with i zeros, j ones, last bit = 1
        static long long dp0[201][201], dp1[201][201];
        static long long pref0[201][201], pref1[201][201];

        // initialize
        for (int i = 0; i <= zero; ++i)
            for (int j = 0; j <= one; ++j)
                dp0[i][j] = dp1[i][j] = pref0[i][j] = pref1[i][j] = 0;

        // base: first element can be 0 or 1
        for (int i = 1; i <= zero && i <= limit; ++i) {
            dp0[i][0] = 1;                    // i zeros, 0 ones, last is 0, whole prefix is a single block of 0s
        }
        for (int j = 1; j <= one && j <= limit; ++j) {
            dp1[0][j] = 1;                    // 0 zeros, j ones, last is 1, whole prefix is a single block of 1s
        }

        // build prefix sums on rows and columns iteratively
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                // build prefix sums from already-filled dp
                long long up0 = (i ? pref0[i - 1][j] : 0);
                long long up1 = (i ? pref1[i - 1][j] : 0);
                long long left0 = (j ? pref0[i][j - 1] : 0);
                long long left1 = (j ? pref1[i][j - 1] : 0);
                long long diag0 = (i && j ? pref0[i - 1][j - 1] : 0);
                long long diag1 = (i && j ? pref1[i - 1][j - 1] : 0);

                pref0[i][j] = (dp0[i][j] + up0 + left0 - diag0) % MOD;
                if (pref0[i][j] < 0) pref0[i][j] += MOD;
                pref1[i][j] = (dp1[i][j] + up1 + left1 - diag1) % MOD;
                if (pref1[i][j] < 0) pref1[i][j] += MOD;

                if (i == 0 && j == 0) continue; // nothing to extend

                // transition to place a 0 at (i, j)
                if (i > 0) {
                    int maxZeros = min(i, limit);
                    int li = i - maxZeros; // earliest starting index for a block of 0s ending at i
                    int ri = i - 1;        // previous index in zeros dimension

                    // sum over k in [1..maxZeros]: take block size k of 0s
                    // we need dp states at (i - k, j) with last bit = 1 (switch) or 0 (extend but bounded by limit)
                    // this becomes sum of dp1[li..ri][j] in i-dimension
                    long long s1 = pref1[ri][j] - (li ? pref1[li - 1][j] : 0);
                    s1 %= MOD;
                    if (s1 < 0) s1 += MOD;

                    long long s0 = pref0[ri][j] - (li ? pref0[li - 1][j] : 0);
                    s0 %= MOD;
                    if (s0 < 0) s0 += MOD;

                    dp0[i][j] = (dp0[i][j] + s1 + s0) % MOD;
                }

                // transition to place a 1 at (i, j)
                if (j > 0) {
                    int maxOnes = min(j, limit);
                    int lj = j - maxOnes;
                    int rj = j - 1;

                    long long s0 = pref0[i][rj] - (lj ? pref0[i][lj - 1] : 0);
                    s0 %= MOD;
                    if (s0 < 0) s0 += MOD;

                    long long s1 = pref1[i][rj] - (lj ? pref1[i][lj - 1] : 0);
                    s1 %= MOD;
                    if (s1 < 0) s1 += MOD;

                    dp1[i][j] = (dp1[i][j] + s0 + s1) % MOD;
                }
            }
        }

        long long ans = (dp0[zero][one] + dp1[zero][one]) % MOD;
        if (ans < 0) ans += MOD;
        return (int)ans;
    }
};
