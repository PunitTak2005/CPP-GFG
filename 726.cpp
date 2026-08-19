class Solution {
    long long countLessEqual(vector<int>& arr, long long target) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                long long sum = 1LL * arr[i] + arr[left] + arr[right];

                if (sum <= target) {
                    // All indices from left+1 to right work with i and left
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }

  public:
    int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());

        long long ans = countLessEqual(arr, r) - countLessEqual(arr, 1LL * l - 1);
        return (int)ans;
    }
};
