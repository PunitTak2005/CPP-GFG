class Solution {
public:
    int mirrorDistance(int n) {
        long long x = n;
        long long rev = 0;

        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        long long diff = x - rev;   // x is 0 here; using n instead is clearer
        diff = (long long)n - rev;  // better: use original n
        if (diff < 0) diff = -diff; // abs without overflow worries in this range

        return (int)diff;
    }
};
