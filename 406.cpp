class Solution {
  public:
    bool isPalinSent(string &s) {
        int i = 0, j = s.length() - 1;

        // Compares character until they are equal
        while (i < j) {

            // Skip non alphabet character
            // from left side
            if (!isalnum(s[i]))
                i++;

            // Skip non alphabet character
            // from right side
            else if (!isalnum(s[j]))
                j--;

            // If characters are equal
            // update the pointers
            else if (tolower(s[i]) == tolower(s[j]))
                i++, j--;

            // If characters are not equal then
            // sentence is not palindrome
            else
                return false;
        }

        // Return true as sentence is palindrome
        return true;
    }
};
