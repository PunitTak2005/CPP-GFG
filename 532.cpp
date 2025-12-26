class Solution {
  public:
    int kthMissing(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int missingBefore = arr[i] - (i + 1);
            if (missingBefore >= k) {
                // kth missing lies before arr[i]
                return k + i;
            }
        }
        // if even up to arr[n-1] we did not reach k,
        // kth missing is after the last element
        return k + n;
    }
};
