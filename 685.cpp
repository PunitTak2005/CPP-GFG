class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int freq[3] = {0, 0, 0};  // freq of a,b,c
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;

            // Shrink from left while window still contains all three chars
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // All substrings starting at 'left' and ending at any index
                // from 'right' to 'n-1' are valid
                ans += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return (int)ans;
    }
};
