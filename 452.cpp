class Solution {
  public:
    // Function to reverse elements in the deque between indices start and end
    void reverseDeque(deque<int>& dq, int start, int end) {
        while (start < end) {
            swap(dq[start], dq[end]);
            start++;
            end--;
        }
    }

    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();

        // If deque is empty, nothing to rotate
        if (n == 0)
            return;

        // Use modulo to avoid unnecessary full rotations
        k = k % n;
        if (k == 0)
            return;

        // Right rotation (clockwise)
        if (type == 1) {
            reverseDeque(dq, 0, n - 1);
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);

            // Left rotation (anti-clockwise)
        } else if (type == 2) {
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);
            reverseDeque(dq, 0, n - 1);
        }
    }
};
