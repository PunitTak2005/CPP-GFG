class Solution {
  public:
    int maxProduct(int n) {
        // Edge case: mandatory cut, so for n=2 return 1*1=1
        if (n <= 3) return 1 * (n - 1);
        
        // Greedily cut out factors of 3
        int a = n / 3;  // number of 3s
        int b = n % 3;  // remainder
        
        if (b == 0) {
            // n is multiple of 3: return 3^a
            return pow(3, a);
        } else if (b == 1) {
            // remainder 1: replace one 3 with 2*2 (since 2*2 > 1*3)
            return pow(3, a - 1) * 4;
        } else {
            // remainder 2: keep the 2
            return pow(3, a) * 2;
        }
    }
};
