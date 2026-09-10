class Solution {
public:
    int pairCount(int x, int y) {
        if (y % x != 0) return 0;

        int n = y / x;
        int count = 0;

        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                int e = n / d;

                if (__gcd(d, e) == 1) {
                    if (d == e) count += 1;  // (a, b) same
                    else count += 2;         // (a, b) and (b, a)
                }
            }
        }

        return count;
    }
};
