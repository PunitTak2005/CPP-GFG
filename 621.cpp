class Solution {
public:
    int countStrings(int n) {
        if (n == 1) return 2;
        if (n == 2) return 3;

        long long prev2 = 2; // dp[1]
        long long prev1 = 3; // dp[2]
        long long curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;   // Fibonacci-like recurrence
            prev2 = prev1;
            prev1 = curr;
        }

        return (int)prev1;
    }
};
