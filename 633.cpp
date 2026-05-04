class Solution {
  public:
    int isPallindrome(long long N) {
        // get binary representation
        string s;
        while (N > 0) {
            s.push_back((N & 1) + '0');
            N >>= 1;
        }
        // currently bits are in reverse order; reverse to get normal binary
        reverse(s.begin(), s.end());
        
        // check palindrome
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};
