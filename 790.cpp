class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        const int INF = 1e9;
        int maxArea = max({s, m, l});
        int MAX = x + maxArea;  // safe upper bound

        vector<int> dp(MAX + 1, INF);
        dp[0] = 0;

        // Unbounded knapsack for each pizza type
        auto update = [&](int area, int cost) {
            for (int a = area; a <= MAX; ++a) {
                if (dp[a - area] != INF) {
                    dp[a] = min(dp[a], dp[a - area] + cost);
                }
            }
        };

        update(s, cs);
        update(m, cm);
        update(l, cl);

        int ans = INF;
        for (int a = x; a <= MAX; ++a) {
            ans = min(ans, dp[a]);
        }
        return ans;
    }
};
