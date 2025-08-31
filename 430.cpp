
class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;

        // Iterate over all subarrays of size k
        for (int i = 0; i <= n - k; i++) {

            // Frequency map to count elements in the current window
            unordered_map<int, int> freq;

            // Track the mode and its maximum frequency
            int mode = INT_MAX;
            int maxFreq = 0;

            // Traverse the current window and build frequency map
            for (int j = i; j < i + k; j++) {
                freq[arr[j]]++;

                // Update mode based on frequency and value (tie-breaker)
                if (freq[arr[j]] > maxFreq || 
                   (freq[arr[j]] == maxFreq && arr[j] < mode)) {
                    maxFreq = freq[arr[j]];
                    mode = arr[j];
                }
            }

            // Add the mode of this subarray to the total sum
            sum += mode;
        }

        return sum;
    }
};
