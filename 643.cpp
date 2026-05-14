#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> ans;
        if (m > n) return ans;

        // Build LPS (longest proper prefix which is also suffix) for pattern b
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (b[i] == b[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // KMP search of b in a
        for (int i = 0, j = 0; i < n; ) {
            if (a[i] == b[j]) {
                ++i; ++j;
                if (j == m) {
                    // match ends at i-1, starts at i-m
                    ans.push_back(i - m);
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
        return ans;
    }
};
