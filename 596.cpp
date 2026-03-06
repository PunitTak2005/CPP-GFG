class Solution {
public:
    string minWindow(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return "";

        vector<int> need(256, 0), have(256, 0);
        for (char c : p) need[(unsigned char)c]++;

        int required = 0;
        for (int i = 0; i < 256; i++)
            if (need[i] > 0) required += need[i];

        int formed = 0;
        int minLen = INT_MAX, start = -1;
        int l = 0;

        for (int r = 0; r < n; r++) {
            unsigned char c = s[r];
            have[c]++;
            if (need[c] > 0 && have[c] <= need[c])
                formed++;

            while (formed == m) {
                int currLen = r - l + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    start = l;
                }
                unsigned char cl = s[l];
                have[cl]--;
                if (need[cl] > 0 && have[cl] < need[cl])
                    formed--;
                l++;
            }
        }

        if (start == -1) return "";   // change here
        return s.substr(start, minLen);
    }
};
