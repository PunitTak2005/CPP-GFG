class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {

        int n = arr.size();

        // sort using comparator function
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            if (abs(a - x) < abs(b - x))
                return true;
            else
                return false;
        });
    }
};
