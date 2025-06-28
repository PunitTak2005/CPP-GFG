class Solution {
  public:
    // Function to check if mid can
    // be maximum sub-arrays sum
    bool check(int mid, vector<int>& arr, int k) {

        int n = arr.size();
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {

            // If individual element is greater
            // maximum possible sum
            if (arr[i] > mid)
                return false;

            // Increase sum of current sub - arr
            sum += arr[i];

            // If the sum is greater than
            // mid increase count
            if (sum > mid) {

                count++;
                sum = arr[i];
            }
        }
        count++;

        if (count <= k)
            return true;
        return false;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int max = *max_element(arr.begin(), arr.end());

        // Max subarr sum, considering subarr of length 1
        int start = max;

        // Max subarr sum, considering subarr of length n
        int end = 0;

        for (int i = 0; i < n; i++) {

            end += arr[i];
        }

        // ans stores possible
        // maximum sub arr sum
        int ans = 0;
        while (start <= end) {

            int mid = (start + end) / 2;

            // If mid is possible solution
            // Put ans = mid;
            if (check(mid, arr, k)) {

                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
