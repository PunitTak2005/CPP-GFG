class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;

        // Iterate over the array
        for (int i = 1; i < n; i++)
            // Update ans with maximum sum of current and previous element
            ans = max(arr[i] + arr[i - 1], ans);

        // Return the maximum sum
        return ans;
    }
};
