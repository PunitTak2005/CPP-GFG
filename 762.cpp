class Solution {
  public:
    int minProd(vector<int>& arr) {
        int neg = 0;            // count of negative numbers
        int zero = 0;           // count of zeros
        int prod = 1;           // product of all non-zero elements
        int mnNegAbs = INT_MAX; // smallest absolute value among negatives
        int mnPos = INT_MAX;    // smallest positive value

        for (int x : arr) {
            if (x == 0) {
                zero++;
                continue;
            }

            prod *= x;

            if (x < 0) {
                neg++;
                mnNegAbs = min(mnNegAbs, abs(x));
            } else {
                mnPos = min(mnPos, x);
            }
        }

        // All elements are zero
        if (neg == 0 && mnPos == INT_MAX) {
            return 0;
        }

        // If there is at least one negative number
        if (neg > 0) {
            // Odd number of negatives => product of all non-zero elements is already
            // minimum
            if (neg % 2 == 1) {
                return prod;
            }

            // Even number of negatives => remove one negative with smallest abs value
            return prod / (-mnNegAbs);
        }

        // No negative numbers
        if (zero > 0) {
            return 0;
        }

        // Only positive numbers
        return mnPos;
    }
};
