class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int n = left; n <= right; ++n) {
            int bits = __builtin_popcount(n);
            if (isPrime(bits)) ans++;
        }
        return ans;
    }
};
