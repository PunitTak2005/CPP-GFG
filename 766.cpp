class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        long long keep = 0; // arr[0] is unchanged
        long long one = 0;  // arr[0] is replaced by 1

        for (int i = 1; i < n; i++) {
            long long newKeep = max(
                keep + abs(arr[i] - arr[i - 1]),
                one + abs(arr[i] - 1)
            );

            long long newOne = max(
                keep + abs(1 - arr[i - 1]),
                one
            );

            keep = newKeep;
            one = newOne;
        }

        return max(keep, one);
    }
};
