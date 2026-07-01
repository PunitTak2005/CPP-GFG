class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        // overall max sum
        int maxSum = arr[0];

        // max subarray sum ending here with no element skipped
        int noSkip = arr[0];

        // max subarray sum ending here with one element skipped
        int oneSkip = 0;

        for (int i = 1; i < n; i++) {
            oneSkip = max(noSkip, oneSkip + arr[i]);
            noSkip = max(arr[i], noSkip + arr[i]);
            maxSum = max({maxSum, noSkip, oneSkip});
        }

        return maxSum;
    }
};
