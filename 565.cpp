class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // First subarray must start at 0
        long long base = nums[0];

        // stSmall: k-2 smallest elements in current window, stLarge: the rest
        multiset<int> stSmall, stLarge;
        long long sumSmall = 0;

        auto adjust = [&]() {
            while ((int)stSmall.size() < k - 2 && !stLarge.empty()) {
                auto it = stLarge.begin();      // smallest in large
                int x = *it;
                stLarge.erase(it);
                stSmall.insert(x);
                sumSmall += x;
            }
            while ((int)stSmall.size() > k - 2) {
                auto it = prev(stSmall.end());  // largest in small
                int x = *it;
                stSmall.erase(it);
                stLarge.insert(x);
                sumSmall -= x;
            }
        };

        auto add = [&](int x) {
            // editorial: compare with smallest in stLarge if exists
            if (!stLarge.empty() && x >= *stLarge.begin()) {
                stLarge.insert(x);
            } else {
                stSmall.insert(x);
                sumSmall += x;
            }
            adjust();
        };

        auto removeVal = [&](int x) {
            auto it1 = stSmall.find(x);
            if (it1 != stSmall.end()) {
                sumSmall -= *it1;
                stSmall.erase(it1);
            } else {
                auto it2 = stLarge.find(x);
                if (it2 != stLarge.end()) stLarge.erase(it2);
            }
            adjust();
        };

        long long ans = LLONG_MAX;

        // i is the start of the last subarray, must be >= 2 so that
        // there is at least one middle subarray (k >= 3)
        int L = 1; // window [L .. i-1]
        for (int i = 2; i < n; ++i) {
            // expand window to include i-1
            add(nums[i - 1]);

            // shrink left if window too long: [i - dist .. i - 1]
            while (L < i - dist) {
                removeVal(nums[L]);
                ++L;
            }

            // we need k-2 middle starts in the window
            if ((int)stSmall.size() == k - 2) {
                long long cur = base + nums[i] + sumSmall;
                ans = min(ans, cur);
            }
        }

        return ans;
    }
};
