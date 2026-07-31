class Solution {
  public:
    static const int MOD = 1e9 + 7;

    int modPow(int exp) {
        int res = 1, base = 2;

        while (exp) {
            if (exp & 1)

                // 1LL temporarily promotes the multiplication to 64-bit to prevent
                // overflow
                res = (1LL * res * base) % MOD;

            base = (1LL * base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int countSubsets(vector<int>& arr) {
        vector<int> mask(31, 0);
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        // Compute prime factor mask for every valid number.
        for (int num = 2; num <= 30; num++) {

            // Numbers having a squared prime factor cannot be part of a good subset.
            if (num % 4 == 0 || num % 9 == 0 || num == 25)
                continue;

            for (int i = 0; i < 10; i++) {
                if (num % primes[i] == 0)
                    mask[num] |= (1 << i);
            }
        }

        vector<int> cnt(31, 0);
        vector<int> dp(1024, 0);

        int ones = 0;
        dp[0] = 1;

        // Count occurrences of each number.
        for (int x : arr) {
            if (x == 1)
                ones++;
            else if (mask[x] != 0)
                cnt[x]++;
        }

        for (int num = 2; num <= 30; num++) {
            if (cnt[num] == 0)
                continue;

            // dp[state] = number of ways to form the prime set represented by state.
            for (int state = 1023; state >= 0; state--) {

                // Current number cannot be added if it shares a prime factor.
                if (state & mask[num])
                    continue;

                // 1LL handles the intermediate math without needing long long variables
                dp[state | mask[num]] =
                    (dp[state | mask[num]] + 1LL * dp[state] * cnt[num]) % MOD;
            }
        }

        int ans = 0;

        // Sum all valid non-empty states. Additions do not overflow a 32-bit int here.
        for (int ways : dp)
            ans = (ans + ways) % MOD;

        // Remove the empty subset.
        ans = (ans - 1 + MOD) % MOD;

        // Each 1 can either be included or excluded independently.
        ans = (1LL * ans * modPow(ones)) % MOD;

        return ans;
    }
};
