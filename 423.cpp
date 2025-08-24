class Solution {
  public:
    // Function to check if the given number of
    // days is valid for creating bouquets
    bool check(vector<int>& arr, int k, int m, int days) {
        int bouquets = 0;
        int cnt = 0;

        // Iterate through the bloom
        // days of the flowers
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) {
                cnt += 1;
            } else {

                // If the current bloom day count
                // is greater than days, update
                // the bouquets and reset count
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        // Check if current bouquets are greater
        // than or equal to the desired
        // number of bouquets (m)
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        int lo = 0;
        int hi = *max_element(arr.begin(), arr.end());
        int res = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(arr, k, m, mid)) {

                // If the current mid is valid, update the result
                // and adjust the search range
                res = mid;
                hi = mid - 1;
            } else {

                // If the current mid is not valid, adjust the
                // search range
                lo = mid + 1;
            }
        }
        return res;
    }
};
