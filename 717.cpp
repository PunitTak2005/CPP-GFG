class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // Sort the array to process elements in descending order
        sort(arr.begin(), arr.end());
        int ans = 0;

        while (true) {
            bool allZero = true; // Flag to check if all elements are zero

            // Iterate from the largest to the smallest element
            for (int i = arr.size() - 1; i >= 0; --i) {
                if (arr[i] % 2 == 1) {
                    arr[i]--; // Decrement odd elements
                    ans++;    // Count the decrement operation
                }
                if (arr[i] != 0)
                    allZero = false; // Check if the element is non-zero
                arr[i] /= 2;         // Halve the element
            }

            if (allZero)
                break; // Break if all elements are zero
            ans++;     // Count the halving operation
        }
        return ans; // Return the total number of operations
    }
};
