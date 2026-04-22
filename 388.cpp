class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        int q = queries.size();

        // build prefix sum
        vector<long long> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + arr[i];
        }

        vector<int> ans;
        ans.reserve(q);

        for (int i = 0; i < q; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = pref[r] - (l > 0 ? pref[l - 1] : 0LL);
            int len = r - l + 1;
            int mean = static_cast<int>(sum / len); // floor via integer division
            ans.push_back(mean);
        }

        return ans;
    }
};
