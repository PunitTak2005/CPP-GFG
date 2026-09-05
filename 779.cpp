class Solution
{
public:
    int longestSubseq(vector<int> &arr)
    {
        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : arr)
        {
            int best = 1;
            if (dp.count(x - 1)) best = max(best, dp[x - 1] + 1);
            if (dp.count(x + 1)) best = max(best, dp[x + 1] + 1);

            dp[x] = max(dp[x], best);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
