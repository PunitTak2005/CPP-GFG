class Solution {
public:
    int minTime(int n, int s1, int s2) {
        int low = 1;
        int high = n * min(s1, s2);

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long done = (long long)(mid / s1) + (long long)(mid / s2);

            if (done >= n)
                high = mid;      // mid may be the answer
            else
                low = mid + 1;   // need more time
        }

        return low;
    }
};
