class Solution {
  public:
    int maxValue(int n) {
        int ans = 0;
        int consecutiveOnes = 0;

        for (int i = 30; i >= 0; i--) {
            if ((n >> i) & 1) {
                if (consecutiveOnes < 2) {
                    ans |= (1 << i);
                    consecutiveOnes++;
                } else {
                    // Must clear this bit to avoid 111
                    consecutiveOnes = 0;
                }
            } else {
                consecutiveOnes = 0;
            }
        }

        return ans;
    }
};
