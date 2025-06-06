class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int res = 0;

        // Hash map to store first occurrence of each difference
        unordered_map<int, int> diffMap;

        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];

            int currentDiff = sum1 - sum2;

            // If difference is 0, entire subarray
            // from 0 to i has equal sum
            if (currentDiff == 0) {
                res = max(res, i + 1);
            }

            // If this difference has been seen before
            else if (diffMap.find(currentDiff) != diffMap.end()) {
                res = max(res, i - diffMap[currentDiff]);
            } else {

                // Store first occurrence of this difference
                diffMap[currentDiff] = i;
            }
        }

        return res;
    }
};
