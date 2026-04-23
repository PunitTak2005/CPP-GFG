class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        // Group indices by value
        unordered_map<int, vector<int>> mp;
        mp.reserve(n * 2);
        mp.max_load_factor(0.7);
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }

        // For each group of equal values, compute contributions
        for (auto &p : mp) {
            auto &idx = p.second;          // all indices having this value
            int m = idx.size();
            if (m == 1) continue;         // only one occurrence → all distances are 0

            // prefix sums of indices
            vector<long long> pref(m, 0);
            pref[0] = idx[0];
            for (int i = 1; i < m; ++i) {
                pref[i] = pref[i - 1] + idx[i];
            }

            long long total = pref[m - 1];

            for (int i = 0; i < m; ++i) {
                long long pos   = idx[i];

                // left side: indices[0..i-1]
                long long leftCount = i;
                long long leftSum   = (i > 0 ? pref[i - 1] : 0);
                long long left      = pos * leftCount - leftSum;

                // right side: indices[i+1..m-1]
                long long rightCount = m - 1 - i;
                long long rightSum   = total - pref[i];
                long long right      = rightSum - pos * rightCount;

                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};
