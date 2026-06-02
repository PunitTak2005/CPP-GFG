class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int totalSum = 0;
        
        // Greedy: pair from the end (larger elements first) to maximize sum
        int i = n - 1;
        while (i > 0) {
            // Check if current pair (arr[i-1], arr[i]) has difference < k
            if (arr[i] - arr[i-1] < k) {
                // Valid pair - include both elements in sum
                totalSum += arr[i] + arr[i-1];
                i -= 2;  // Move past this pair
            } else {
                i--;  // Try next element
            }
        }
        
        return totalSum;
    }
};
