class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // Largest power of 2 <= n
        int p = 0;
        while ((1 << (p + 1)) <= n) p++;

        // Bits from MSB of all numbers from 1 to 2^p - 1
        int bitsUpTo2p = p * (1 << (p - 1));

        // MSB bits from 2^p to n
        int msbBits = n - (1 << p) + 1;

        // Remaining bits
        int rest = n - (1 << p);

        return bitsUpTo2p + msbBits + countSetBits(rest);
    }
};
