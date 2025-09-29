class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int best = INT_MIN;
        int curr = 0;

        for (int i = a; i <= b; i++) {
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
        }

        return best;
    }
};
