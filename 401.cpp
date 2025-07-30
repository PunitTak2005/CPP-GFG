class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {

        // unordered_map to store prefix sums frequencies
        unordered_map<int, int> prefixSums;

        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Add current element to sum so far.
            currSum += arr[i];

            // If currSum is equal to desired sum, then a new
            // subarray is found. So increase count of subarrays.
            if (currSum == k)
                res++;

            // Check if the difference exists in the prefixSums map.
            if (prefixSums.find(currSum - k) != prefixSums.end())
                res += prefixSums[currSum - k];

            prefixSums[currSum]++;
        }

        return res;
    }
};
