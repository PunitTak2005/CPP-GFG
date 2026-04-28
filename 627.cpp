class Solution {
public:
    int longestSubstr(string &s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int maxFreq = 0;   // max frequency of any character in current window
        int ans = 0;
        int n = s.size();

        while (right < n) {
            int idx = s[right] - 'A';
            freq[idx]++;
            maxFreq = max(maxFreq, freq[idx]);

            // If changes needed > k, shrink from left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
