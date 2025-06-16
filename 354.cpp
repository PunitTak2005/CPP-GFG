class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // Sort the array to handle values in increasing order
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Prefix sum array to compute total coins quickly
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + arr[i];

        int ans = INT_MAX, prev = 0;

        for (int i = 0; i < n; i++) {
            // Update `prev` only when
            // arr[i] is different from arr[i - 1] else continue

            // This represents total coins from piles smaller than arr[i]
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            if (i > 0) {
                prev = prefix[i - 1];
            }

            // Find the first index where arr[pos] > arr[i] + k
            int pos = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();

            // Total coins to remove:
            // - `prev` for coins from smaller piles (before i)
            // - `(prefix[n - 1] - prefix[pos - 1])` is the total
            // from piles after pos [arr[i], arr[i]+k]

            // - Subtract the part that is allowed to stay: (n - pos) * (arr[i] + k)
            int totalToRemove =
                prev + prefix[n - 1] - prefix[pos - 1] - (n - pos) * (arr[i] + k);

            // Update answer with minimum coins removed
            ans = min(ans, totalToRemove);
        }

        return ans;
    }
};
