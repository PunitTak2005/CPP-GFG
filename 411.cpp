class Solution {
  public:
    int countPS(string& s) {
        int n = s.size();
        int count = 0;

        // count odd length palndrome substrings
        // with str[i] as center.
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }

        // count even length palindrome substrings
        // where str[i] is first center.
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }
        return count;
    }
};
