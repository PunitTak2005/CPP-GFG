class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;            // position of previous '1'
        int pos = 0;              // current bit position (0-based)

        while (n > 0) {
            if (n & 1) {          // if current bit is 1
                if (prev != -1) {
                    ans = max(ans, pos - prev);
                }
                prev = pos;
            }
            pos++;
            n >>= 1;              // move to next bit
        }

        return ans;
    }
};
