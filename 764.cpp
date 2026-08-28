class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;

        int oddCount = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                oddCount++;
                mid = char('a' + i);
            }
        }

        if (oddCount > 1) return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = freq[i] / 2;
        }

        int m = n / 2;
        string left;
        bool alreadyGreater = false;

        for (int i = 0; i < m; i++) {
            bool placed = false;

            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) continue;

                char ch = char('a' + c);

                // If prefix is still equal, do not choose below target[i].
                if
