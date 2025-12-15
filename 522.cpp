class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        vector<long long> prefixEven(n, 0), prefixOdd(n, 0);

        // Build prefix sums
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefixEven[i] = prefixEven[i-1];
                prefixOdd[i] = prefixOdd[i-1];
            }
            if (i % 2 == 0) prefixEven[i] += arr[i];
            else prefixOdd[i] += arr[i];
        }

        long long totalEven = prefixEven[n-1];
        long long totalOdd = prefixOdd[n-1];
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long leftEven = (i > 0 ? prefixEven[i-1] : 0);
            long long leftOdd = (i > 0 ? prefixOdd[i-1] : 0);

            long long rightEven = totalEven - prefixEven[i];
            long long rightOdd = totalOdd - prefixOdd[i];

            // After removal, right side flips parity
            long long newEvenSum = leftEven + rightOdd;
            long long newOddSum = leftOdd + rightEven;

            if (newEvenSum == newOddSum) count++;
        }

        return count;
    }
};
