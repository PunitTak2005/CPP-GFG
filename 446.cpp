class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int len = 0;
        int n = arr.size();

        // Check every subarray
        for (int i = 0; i < n; i++) {
            int maxi = arr[i];
            for (int j = i; j < n; j++) {
                // update max in subarray
                maxi = max(maxi, arr[j]);
                if (j - i + 1 >= maxi) {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};
