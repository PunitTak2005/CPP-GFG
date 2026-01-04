class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            int cnt = 0;
            int sum = 0;

            // Check divisors from 1 to sqrt(num)
            for (int d = 1; d * d <= num; ++d) {
                if (num % d == 0) {
                    int d2 = num / d;

                    // d is a divisor
                    ++cnt;
                    sum += d;

                    // paired divisor (avoid double-counting when d*d == num)
                    if (d2 != d) {
                        ++cnt;
                        sum += d2;
                    }

                    // Early stop if more than 4 divisors
                    if (cnt > 4) break;
                }
            }

            if (cnt == 4)
                ans += sum;
        }

        return ans;
    }
};
