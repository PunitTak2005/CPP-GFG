class Solution {
public:
    char findKthBit(int n, int k) {
        return solve(n, k);
    }
    
private:
    char solve(int n, int k) {
        if (n == 1) return '0';                 // S1 = "0"
        
        int len = (1 << n) - 1;                 // length of Sn
        int mid = len / 2 + 1;                 // middle position (1-based)
        
        if (k == mid) return '1';              // middle is always '1' for n > 1
        
        if (k < mid) {
            // in left half, same as Sn-1
            return solve(n - 1, k);
        } else {
            // in right half: mirror index to left, then invert
            int mirror = len - k + 1;          // mapped index in left half
            char c = solve(n - 1, mirror);
            return (c == '0') ? '1' : '0';
        }
    }
};
