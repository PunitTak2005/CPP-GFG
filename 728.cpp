class Solution {
  public:
    int transform(string &s1, string &s2) {
        if (s1.size() != s2.size()) return -1;
        
        // Both strings must contain the same characters with same frequency
        int freq[256] = {0};
        for (char ch : s1) freq[(unsigned char)ch]++;
        for (char ch : s2) freq[(unsigned char)ch]--;
        
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) return -1;
        }
        
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int operations = 0;
        
        // Match from the end. Any unmatched s1 character
        // must be moved to the front.
        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--;
            } else {
                operations++;
            }
            i--;
        }
        
        return operations;
    }
};
