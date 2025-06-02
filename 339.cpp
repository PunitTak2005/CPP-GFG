// Backend complete function template for C++

class Solution {
  public:
    int count(string &s, int k) {
        int n = s.length();
        int ans = 0;

        // Use sliding window technique
        vector<int> freq(26, 0);
        int distinctCnt = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {

            // Expand window and add character
            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1)
                distinctCnt++;

            // Shrink window if distinct characters exceed k
            while (distinctCnt > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0)
                    distinctCnt--;
                i++;
            }

            // Add number of valid substrings ending at j
            ans += j - i + 1;
        }
        return ans;
    }

    // Function to find the number of substrings
    // with exactly k Distinct characters.
    int countSubstr(string &s, int k) {
        int n = s.length();
        int ans = 0;

        // Subtract substrings with at most
        // k-1 distinct characters from substrings
        // with at most k distinct characters
        ans = count(s, k) - count(s, k - 1);

        return ans;
    }
};
