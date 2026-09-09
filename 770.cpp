class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        int best = n;
        int bestSum = digitSum(n);

        // A best candidate can be formed by reducing one digit
        // and replacing all following digits with 9.
        int p = 1;
        while (p <= n) {
            int candidate = (n / (p * 10)) * (p * 10) + ((n / p) % 10 - 1) * p + (p - 1);

            if ((n / p) % 10 > 0 && candidate >= 1 && candidate <= n) {
                int currSum = digitSum(candidate);

                if (currSum > bestSum || (currSum == bestSum && candidate > best)) {
                    bestSum = currSum;
                    best = candidate;
                }
            }

            p *= 10;
        }

        return best;
    }
};
