class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        // computing sum of subarray using formula
        for (int i = 0; i < n; i++)
            result += (arr[i] * (i + 1) * (n - i));

        // return all subarray sum
        return result;
    }
};
