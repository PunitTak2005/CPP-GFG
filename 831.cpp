class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;

        long long ans = 0;
        int even = 1; // count of prefix sums with even parity
        int odd = 0;  // count of prefix sums with odd parity
        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);

            if (parity == 1) {
                ans += even;
                odd++;
            } else {
                ans += odd;
                even++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
