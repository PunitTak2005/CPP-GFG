class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        // Process bits from MSB to LSB.
        for (int bit = 31; bit >= 0 && index < n; bit--) {

            int maxIndex = index;

            // Find an element having the current bit set.
            for (int i = index; i < n; i++) {
                if ((arr[i] & (1 << bit)) && arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            // No pivot found for this bit.
            if ((arr[maxIndex] & (1 << bit)) == 0) {
                continue;
            }

            // Place the pivot at the current index.
            swap(arr[index], arr[maxIndex]);

            // Eliminate the current bit from all other elements.
            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;

        for (int num : arr) {
            ans ^= num;
        }

        return ans;
    }
};
