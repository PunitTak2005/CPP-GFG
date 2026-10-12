class Solution {
  public:
    int minSquares(int n, int m) {
        long long a = n, b = m;
        long long res = 0;

        while (a > 0 && b > 0) {
            if (a < b) swap(a, b);

            // Take all possible b x b squares in one direction
            res += a / b;
            a %= b;
        }

        return (int)res;
    }
};
