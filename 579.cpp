class Solution {
public:
    int reverseBits(int n) {
        unsigned int x = static_cast<unsigned int>(n); // work as unsigned
        unsigned int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            ans <<= 1;          // shift result left
            ans |= (x & 1);     // copy LSB of x
            x >>= 1;            // shift x right (logical because x is unsigned)
        }
        
        return static_cast<int>(ans);
    }
};
