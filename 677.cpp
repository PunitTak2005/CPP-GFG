class Solution {
  public:
    string chooseSwap(string &s) {
        int n = s.size();

        // first[c] = first index where character c appears in s
        // If a character does not appear, its value stays -1.
        vector<int> first(26, -1);

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            }
        }

        char x = 0, y = 0;
        int pos = -1;

        // Find the leftmost position that can be made smaller.
        // At that position, choose the smallest possible character
        // that appears later in the string.
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';

            for (int c = 0; c < cur; c++) {
                // If a smaller character exists after position i,
                // swapping these two characters can improve the string.
                if (first[c] > i) {
                    pos = i;
                    x = s[i];
                    y = char('a' + c);
                    break;
                }
            }

            if (pos != -1) {
                break;
            }
        }

        // If no beneficial swap exists, return the original string.
        if (pos == -1) {
            return s;
        }

        string res = s;

        // Swap all occurrences of x and y.
        for (char &ch : res) {
            if (ch == x) {
                ch = y;
            } else if (ch == y) {
                ch = x;
            }
        }

        return res;
    }
};
