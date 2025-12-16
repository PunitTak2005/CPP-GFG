class Solution {
public:
    static const long long NEG_INF;

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        vector<vector<int>> g(n + 1);
        for (auto &e : hierarchy) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
        }

        // dp[state][u][c]:
        // state 0: u not bought
        // state 1: u bought at full price
        // state 2: u bought at discounted price
        vector<vector<vector<long long>>> dp(
            3, vector<vector<long long>>(n + 1,
                vector<long long>(budget + 1, NEG_INF))
        );

        function<void(int)> dfs = [&](int u) {
            int fullCost = present[u - 1];
            int discCost = present[u - 1] / 2;
            long long profitFull = (long long)future[u - 1] - fullCost;
            long long profitDisc = (long long)future[u - 1] - discCost;

            dp[0][u][0] = 0;
            if (fullCost <= budget)
                dp[1][u][fullCost] = profitFull;
            if (discCost <= budget)
                dp[2][u][discCost] = profitDisc;

            for (int v : g[u]) {
                dfs(v);

                vector<long long> ndp0(budget + 1, NEG_INF);
                vector<long long> ndp1(budget + 1, NEG_INF);
                vector<long long> ndp2(budget + 1, NEG_INF);

                // u not bought: child cannot use discount (only state 0 or 1)
                for (int c1 = 0; c1 <= budget; ++c1) {
                    if (dp[0][u][c1] == NEG_INF) continue;
                    for (int c2 = 0; c1 + c2 <= budget; ++c2) {
                        long long bestChild = max(dp[0][v][c2], dp[1][v][c2]);
                        if (bestChild == NEG_INF) continue;
                        ndp0[c1 + c2] =
                            max(ndp0[c1 + c2], dp[0][u][c1] + bestChild);
                    }
                }

                // u bought full: child may use discount
                for (int c1 = 0; c1 <= budget; ++c1) {
                    if (dp[1][u][c1] == NEG_INF) continue;
                    for (int c2 = 0; c1 + c2 <= budget; ++c2) {
                        long long bestChild = dp[0][v][c2];
                        bestChild = max(bestChild, dp[1][v][c2]);
                        bestChild = max(bestChild, dp[2][v][c2]);
                        if (bestChild == NEG_INF) continue;
                        ndp1[c1 + c2] =
                            max(ndp1[c1 + c2], dp[1][u][c1] + bestChild);
                    }
                }

                // u bought discounted: same child options as above
                for (int c1 = 0; c1 <= budget; ++c1) {
                    if (dp[2][u][c1] == NEG_INF) continue;
                    for (int c2 = 0; c1 + c2 <= budget; ++c2) {
                        long long bestChild = dp[0][v][c2];
                        bestChild = max(bestChild, dp[1][v][c2]);
                        bestChild = max(bestChild, dp[2][v][c2]);
                        if (bestChild == NEG_INF) continue;
                        ndp2[c1 + c2] =
                            max(ndp2[c1 + c2], dp[2][u][c1] + bestChild);
                    }
                }

                dp[0][u].swap(ndp0);
                dp[1][u].swap(ndp1);
                dp[2][u].swap(ndp2);
            }
        };

        dfs(1);

        long long ans = 0;
        for (int c = 0; c <= budget; ++c) {
            ans = max(ans, dp[0][1][c]);
            ans = max(ans, dp[1][1][c]);
            ans = max(ans, dp[2][1][c]);
        }
        return (int)ans;
    }
};

const long long Solution::NEG_INF = (long long)-4e18;
