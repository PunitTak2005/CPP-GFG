class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // cnt[v] = how many positions have absolute difference v
        vector<long long> cnt(maxDiff + 1, 0);
        for (int d : diff) cnt[d]++;

        long long k = (long long)k1 + k2;

        // Reduce the largest differences greedily.
        for (int v = maxDiff; v > 0 && k > 0; v--) {
            if (cnt[v] == 0) continue;

            long long use = min(k, cnt[v]);
            cnt[v] -= use;
            cnt[v - 1] += use;
            k -= use;
        }

        long long ans = 0;
        for (long long v = 1; v <= maxDiff; v++) {
            ans += cnt[v] * v * v;
        }

        return ans;
    }
};
