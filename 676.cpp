class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {

        int n = arr.size();

        vector<int> res(n);

        // First prefix requires 0 operations
        res[0] = 0;

        // Calculate minimum operations for each prefix
        for (int i = 1; i < n; i++) {

            // Median of current prefix is arr[i / 2]
            res[i] = res[i - 1] + arr[i] - arr[i / 2];
        }

        return res;
    }
};
