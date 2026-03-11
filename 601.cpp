class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;              // special case

        int mask = 0;
        int m = n;
        while (m > 0) {
            mask = (mask << 1) | 1;        // build mask like 1, 3, 7, 15, ...
            m >>= 1;
        }

        return (~n) & mask;                // flip bits only within mask
    }
};
