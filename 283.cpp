class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        auto dist = [](int a, int b) {
            int ra = a / 6, ca = a % 6;
            int rb = b / 6, cb = b % 6;
            return abs(ra - rb) + abs(ca - cb);
        };

        // dp[i][j]: min extra cost after typing first i letters,
        //           with one finger fixed on letter index j (0..25),
        //           and the **other** finger on word[i-1].
        const int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(26, INF));
        dp[0].assign(26, 0);  // before typing anything, cost = 0 for all j

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int moveBoth = dist(prev, cur); // cost if we move the finger that was on prev

            for (int j = 0; j < 26; ++j) {
                if (dp[i - 1][j] == INF) continue;

                // 1) same finger that typed prev now types cur
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + moveBoth);

                // 2) the other finger (currently at j) types cur, prev-finger stays
                int moveOther = dist(j, cur);
                dp[i][prev] = min(dp[i][prev], dp[i - 1][j] + moveOther);
            }
        }

        int ans = INF;
        for (int j = 0; j < 26; ++j) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};
