class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1, j = tar.size() - 1;
        
        while (i >= 0 && j >= 0) {
            if (pat[i] != tar[j]) {
                i -= 2; // simulate deletion
            } else {
                i--;
                j--;
            }
        }
        
        return j < 0; // true if all of tar is matched
    }
};
