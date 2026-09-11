class Solution {
public:
    int sameMod(vector<int>& arr) {
        int g = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }
        
        // All values are identical
        if (g == 0) return -1;
        
        int count = 0;
        
        // Count divisors of g
        for (int d = 1; 1LL * d * d <= g; d++) {
            if (g % d == 0) {
                count++;
                if (d != g / d) count++;
            }
        }
        
        return count;
    }
};
