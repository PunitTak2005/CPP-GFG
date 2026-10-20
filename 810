class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int>& arr) {
        int n = arr.size();
        int i = 0;

        while (i < n) {
            int j = i;

            // Find the end of the current same-parity run
            while (j + 1 < n && ((arr[j] + arr[j + 1]) % 2 == 0)) {
                j++;
            }

            // Sort this contiguous run in descending order
            sort(arr.begin() + i, arr.begin() + j + 1, greater<int>());

            i = j + 1;
        }

        return arr;
    }
};
