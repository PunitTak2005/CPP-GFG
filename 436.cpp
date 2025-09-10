class Solution {
class Solution {
  public:
    string largestSwap(string &s) {
        char maxDigit = '0';
        int maxIndx = -1;
        int l = -1, r = -1;

        // Traverse from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            // Update maxDigit if current digit is larger
            if (s[i] > maxDigit) {
                maxDigit = s[i];
                maxIndx = i;
            }

            // Found a smaller digit before a larger one
            else if (s[i] < maxDigit) {
                l = i;
                r = maxIndx;
            }
        }

        // If no swap needed, return original
        if (l == -1)
            return s;

        // Perform swap
        swap(s[l], s[r]);

        return s;
    }
};
