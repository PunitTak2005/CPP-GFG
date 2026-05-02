class Solution {
public:
    int findPosition(int n) {
        // If n is 0 or has more than one set bit, return -1
        if (n == 0 || (n & (n - 1)) != 0) {
            return -1;
        }
        
        // Find the position of the set bit
        int position = 1;
        while (n > 0) {
            if (n & 1) {
                return position;
            }
            n >>= 1;
            position++;
        }
        
        return -1;
    }
};
