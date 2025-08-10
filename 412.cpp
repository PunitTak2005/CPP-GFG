class Solution {
public:
    int maxSum(string &s) {
        int n = (int)s.size();
        if (n < 2) return 0;

        // Manacher (odd-length) -> d1[i] = radius (k) so palindrome length = 2*k-1
        vector<int> d1(n, 0);
        int L = 0, R = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > R) ? 1 : min(d1[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d1[i] = k;
            if (i + k - 1 > R) { L = i - k + 1; R = i + k - 1; }
        }

        // compute_left: for each end index j, maximum odd-palindrome length that ends exactly at j
        auto compute_left = [&](const vector<int> &d) {
            int m = (int)d.size();
            vector<int> rightBound(m);
            for (int i = 0; i < m; ++i) rightBound[i] = i + d[i] - 1;

            vector<int> left(m, 0);
            deque<pair<int,int>> dq; // (center_i, rightBound)
            for (int j = 0; j < m; ++j) {
                dq.emplace_back(j, rightBound[j]);          // center j becomes available when j <= current end
                while (!dq.empty() && dq.front().second < j) // remove centers that don't reach j
                    dq.pop_front();
                if (!dq.empty()) {
                    int ci = dq.front().first; // smallest center index among active -> gives max length ending at j
                    left[j] = 2 * (j - ci + 1) - 1;
                } else {
                    left[j] = 0;
                }
            }
            return left;
        };

        vector<int> left = compute_left(d1);

        // For right (max palindrome starting at i) compute on reversed string and map back
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<int> d1r(n, 0);
        L = 0; R = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > R) ? 1 : min(d1r[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && rev[i - k] == rev[i + k]) ++k;
            d1r[i] = k;
            if (i + k - 1 > R) { L = i - k + 1; R = i + k - 1; }
        }
        vector<int> left_rev = compute_left(d1r);
        vector<int> right(n, 0);
        for (int i = 0; i < n; ++i) right[i] = left_rev[n - 1 - i];

        // Relax to get best up to / from each index
        for (int i = 1; i < n; ++i) left[i] = max(left[i], left[i - 1]);
        for (int i = n - 2; i >= 0; --i) right[i] = max(right[i], right[i + 1]);

        // Combine non-overlapping palindromes (split between i-1 and i)
        int ans = 0;
        for (int i = 1; i < n; ++i) ans = max(ans, left[i - 1] + right[i]);
        return ans;
    }
};
