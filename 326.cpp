class Solution {
  public:
    // Function to check if the current value is enough to satisfy the condition
    bool enough(int x, int m, int n, int k) {
        int count = 0;

        // Loop over each row and count the number of elements smaller than or equal to
        // x
        for (int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }

        // Return true if the count is greater than or equal to k
        return count >= k;
    }

    // Function to find the kth smallest element
    int kthSmallest(int m, int n, int k) {
        int lo = 1, hi = m * n;

        // Binary search to find the minimum value that satisfies the condition
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;

            // If enough(mi, m, n, k) returns false, increase the lower bound
            if (!enough(mi, m, n, k))
                lo = mi + 1;

            // Otherwise, decrease the upper bound
            else
                hi = mi;
        }

        // Return the lower bound as the kth smallest element
        return lo;
    }
};
