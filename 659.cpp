class Solution
{
public:
    // Use long long because results can exceed int range for larger n
    long long maxSum(int n)
    {
        // memo[i] will store the best value for i
        static unordered_map<int, long long> memo;

        // If already computed, return it
        auto it = memo.find(n);
        if (it != memo.end())
            return it->second;

        // Base case
        if (n == 0)
            return 0;

        // Recursively compute the best by breaking
        long long breakSum = maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4);

        // Best is either not breaking (i.e., n) or breaking
        long long best = max( (long long)n, breakSum );

        memo[n] = best;
        return best;
    }
};
