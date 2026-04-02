class Solution(object):
    def maximumAmount(self, coins):
        """
        :type coins: List[List[int]]
        :rtype: int
        """
        m, n = len(coins), len(coins[0])

        # dp[i][j][k] = max profit at (i, j) with k neutralizations remaining
        NEG_INF = -10**18
        dp = [[[NEG_INF] * 3 for _ in range(n)] for __ in range(m)]

        # base cell (0,0)
        val = coins[0][0]
        # Option 1: do not neutralize
        dp[0][0][2] = val
        # Option 2: neutralize if robber
        if val < 0:
            dp[0][0][1] = 0

        # fill DP
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                v = coins[i][j]
                for k in range(3):          # k = remaining neutralizations at this cell
                    best = NEG_INF

                    # from top
                    if i > 0:
                        # do not neutralize here
                        best = max(best, dp[i - 1][j][k] + v)
                        # neutralize here (consume 1 neutralization => k+1 in previous cell)
                        if k + 1 < 3:
                            best = max(best, dp[i - 1][j][k + 1])

                    # from left
                    if j > 0:
                        # do not neutralize here
                        best = max(best, dp[i][j - 1][k] + v)
                        # neutralize here
                        if k + 1 < 3:
                            best = max(best, dp[i][j - 1][k + 1])

                    # if v is negative and we are not neutralizing, we should subtract abs(v)
                    # but note: in the above we added v directly; v is already negative
                    # so no further change is needed

                    dp[i][j][k] = best

        return max(dp[m - 1][n - 1])
