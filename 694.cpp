class Solution {
  public:
    int getCount(int n) {
        int count = 0;

        // k represents the number of terms in our consecutive sequence.
        // we need 2 or more consecutive numbers, so k starts at 2.
        for (int k = 2;; k++) {

            long long baseSum = (k * (k - 1)) / 2;

            // if baseSum is greater than or equal to n, a valid sequence
            // of length k is impossible.
            if (baseSum >= n) {
                break;
            }

            // check if (n - baseSum) is perfectly divisible by k
            // if the remainder is 0, a valid starting number 'a' exists
            if ((n - baseSum) % k == 0) {
                count++;
            }
        }

        return count;
    }
};
