class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int diffStart0 = 0; // mismatches if pattern is "0101..."
        
        for (int i = 0; i < n; ++i) {
            char expected = (i % 2 == 0 ? '0' : '1');
            if (s[i] != expected) diffStart0++;
        }
        
        // For pattern "1010...", mismatches are the complement
        int diffStart1 = n - diffStart0;
        return min(diffStart0, diffStart1);
    }
};
