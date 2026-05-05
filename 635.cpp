class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;

        // assuming 32-bit integers
        for (int b = 0; b < 32; ++b) {
            long long cnt1 = 0;
            int mask = 1 << b;

            for (int i = 0; i < n; ++i) {
                if (arr[i] & mask) cnt1++;
            }

            long long cnt0 = n - cnt1;
            long long contrib = cnt1 * cnt0 * (1LL << b);
            ans += contrib;
        }

        return ans;
    }
};
