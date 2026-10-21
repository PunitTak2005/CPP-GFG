class Solution {
  public:
    int minSubarraySum(vector<int>& arr) {
        int cur = arr[0];
        int best = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            cur = min(arr[i], cur + arr[i]);
            best = min(best, cur);
        }

        return best;
    }
};
