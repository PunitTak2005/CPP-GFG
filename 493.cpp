class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ones = 0;
        bool seenZero = false;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones++;
            } else {
                // We hit a zero
                if (seenZero && ones > 0) {
                    // This is a new group of zeros after ones
                    // All ones before this group will pass through it
                    ans += ones;
                }
                seenZero = true;
            }
        }
        
        return ans;
    }
};
