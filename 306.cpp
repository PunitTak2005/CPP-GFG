class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};   // no triplet possible

        // small = smallest so far, mid = second smallest so far
        int small = INT_MAX, mid = INT_MAX;
        int third = INT_MAX;    // will store the third element when found

        for (int x : arr) {
            if (x <= small) {
                // new smallest
                small = x;
            } else if (x <= mid) {
                // x is > small and <= mid: update mid
                mid = x;
            } else {
                // x > mid: we have small < mid < x
                third = x;
                break;
            }
        }

        // if we never broke, no triplet exists
        if (third == INT_MAX) return {};

        // small might have been updated after choosing 'mid',
        // so fix 'small' as any element < mid appearing before 'third'.
        // We just reconstruct by scanning until we see 'mid' or 'third'.
        int first = small, second = mid;
        bool foundFirst = false, foundSecond = false;

        for (int x : arr) {
            if (!foundFirst && x < mid) {
                first = x;
                foundFirst = true;
            }
            if (foundFirst && x > first && x < third) {
                second = x;
                foundSecond = true;
            }
            if (foundFirst && foundSecond && x == third) break;
        }

        return {first, second, third};
    }
};
