class Solution {
  public:
    long long countIncreasing(vector<int>& arr) {
        int n = arr.size();
        long long totalCount = 0;
        long long currentLen = 1; // Every single element is an increasing subarray of length 1

        for (int i = 1; i < n; i++) {
            // Check if the current element continues the increasing sequence
            if (arr[i] > arr[i - 1]) {
                currentLen++;
            } else {
                // Sequence broke, calculate subarrays for the previous chain
                if (currentLen >= 2) {
                    totalCount += (currentLen * (currentLen - 1)) / 2;
                }
                currentLen = 1; // Reset for the new sequence
            }
        }

        // Final check for the last sequence in the array
        if (currentLen >= 2) {
            totalCount += (currentLen * (currentLen - 1)) / 2;
        }

        return totalCount;
    }
};
