class Solution {
public:
    int minFlips(string &s) {
        int n = static_cast<int>(s.size());
        int flipsForZeroStart = 0;

        for (int i = 0; i < n; ++i) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                ++flipsForZeroStart;
            }
        }

        int flipsForOneStart = n - flipsForZeroStart;
        return min(flipsForZeroStart, flipsForOneStart);
    }
};
