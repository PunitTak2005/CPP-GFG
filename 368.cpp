class Solution {
  public:
    int substrCount(string &s, int k) {

        // Return 0 if window size k is greater than the string length
        if (k > s.length())
            return 0;

        int n = s.length();

        // Frequency array for characters a-z
        vector<int> cnt(26, 0);
        int ans = 0;
        int distinctCnt = 0;

        // Preprocess the first k-1 characters
        for (int i = 0; i < k - 1; i++) {
            cnt[s[i] - 'a']++;

            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;
        }

        // Start sliding window
        for (int i = k - 1; i < n; i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;

            // Check if window has exactly k-1 distinct characters
            if (distinctCnt == k - 1)
                ans++;

            // Remove the character going out of the window
            cnt[s[i - k + 1] - 'a']--;

            if (cnt[s[i - k + 1] - 'a'] == 0)
                distinctCnt--;
        }

        return ans;
    }
};
