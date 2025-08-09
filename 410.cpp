class Solution {
public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        if (n <= 1) return -1;

        // Build Z-array
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) {
                l = i; r = i + z[i] - 1;
            }
        }

        int ans = -1;
        // We want the largest L (1 <= L < n) such that s[L..] starts with s[0..n-L-1]
        for (int L = 1; L < n; ++L) {
            if (z[L] >= n - L) ans = L; // valid periodic proper prefix
        }
        return ans;
    }
};
