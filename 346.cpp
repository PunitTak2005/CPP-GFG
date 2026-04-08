class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n - 1;

        while (i < j) {
            // move i forward while it's already 0
            while (i < j && arr[i] == 0) i++;
            // move j backward while it's already 1
            while (i < j && arr[j] == 1) j--;

            // now arr[i] == 1 and arr[j] == 0, swap them
            if (i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
    }
};
