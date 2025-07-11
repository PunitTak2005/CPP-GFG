class Solution {
  public:
    int countConsec(int n) {
        int prev0 = 0, prev1 = 0;
        for (int i = n; i >= 1; i--) {
            // if previous bit is 0, we can place 0 or 1
            int curr0 = prev0 + prev1;

            // if previous bit is 1, placing another 1 creates a valid pair,
            // remaining bits can be anything: 2^(n - i)
            int curr1 = prev0 + (1 << (n - i));

            // update for next round
            prev0 = curr0;
            prev1 = curr1;
        }

        // start from position 1 with previous bit 0
        return prev0;
    }
};
