class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1'000'000'007;
        long long ans = 0;
        int bits = 0;

        for (int i = 1; i <= n; ++i) {
            // If i is a power of 2, its bit-length increases by 1
            if ((i & (i - 1)) == 0) {
                ++bits;
            }
            ans = ((ans << bits) + i) % MOD;
        }
        return (int)ans;
    }
};
