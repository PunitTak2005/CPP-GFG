class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        // build prefix: +1 for >k, -1 otherwise
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1] + (arr[i-1] > k ? 1 : -1);
        }

        // candidates: indices with strictly decreasing prefix values
        vector<int> candidates;
        for (int i = 0; i <= n; ++i) {
            if (candidates.empty() || prefix[i] < prefix[candidates.back()]) {
                candidates.push_back(i);
            }
        }

        int ans = 0;
        // traverse from right to left, trying to pair with earliest smaller prefix
        for (int i = n; i >= 0; --i) {
            while (!candidates.empty() && prefix[i] > prefix[candidates.back()]) {
                ans = max(ans, i - candidates.back());
                candidates.pop_back();
            }
        }
        return ans;
    }
};
