class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int freq[3] = {0, 0, 0};    // freq[0] for '0', freq[1] for '1', freq[2] for '2'
        int distinct = 0;           // how many of {0,1,2} are present in current window
        int ans = INT_MAX;

        while (j < n) {
            int idx = s[j] - '0';
            if (freq[idx] == 0) distinct++;
            freq[idx]++;

            // when window has all 3 chars, try to shrink from left
            while (distinct == 3) {
                ans = min(ans, j - i + 1);

                int leftIdx = s[i] - '0';
                freq[leftIdx]--;
                if (freq[leftIdx] == 0) distinct--;
                i++;
            }

            j++;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
