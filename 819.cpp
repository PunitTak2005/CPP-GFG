class Solution {
public:
    int cntSubsets(vector<int>& arr, int l, int r) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();

        vector<long long> cnt(n + 1, 0);
        for (int x : arr) {
            if (x <= n) cnt[x]++;
        }

        auto power = [&](long long base, long long exp) {
            long long result = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp & 1) result = result * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return result;
        };

        long long ans = 0;
        long long requiredWays = 1;      // product of (2^cnt[v] - 1)
        long long freeCount = n;         // elements not in 0..m

        for (int m = 0; m <= r; m++) {
            if (m > 0) {
                requiredWays = requiredWays * ((power(2, cnt[m - 1]) - 1 + MOD) % MOD) % MOD;
            }

            freeCount -= cnt[m];

            if (m >= l) {
                long long ways = requiredWays * power(2, freeCount) % MOD;
                ans = (ans + ways) % MOD;
            }
        }

        return (int)ans;
    }
};
