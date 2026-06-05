class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos, int tight, int started,
             int prev1, int prev2) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][prev1 + 1][prev2 + 1])
            return dp[pos][tight][started][prev1 + 1][prev2 + 1];

        vis[pos][tight][started][prev1 + 1][prev2 + 1] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child =
                    dfs(pos + 1, ntight, 0, -1, -1);

                ans.cnt += child.cnt;
                ans.sum += child.sum;
            } else {
                int add = 0;

                if (prev2 != -1) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node child =
                    dfs(pos + 1, ntight, 1, d, prev1);

                ans.cnt += child.cnt;
                ans.sum += child.sum + child.cnt * add;
            }
        }

        return dp[pos][tight][started][prev1 + 1][prev2 + 1] = ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, -1, -1).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        auto melidroni = make_pair(num1, num2);
        return solve(num2) - solve(num1 - 1);
    }
};
