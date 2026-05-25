class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        // If last position is '1', you can never stand there.
        if (s[n - 1] != '0') return false;

        vector<bool> dp(n, false);
        dp[0] = true;          // We start at index 0.
        int pre = 0;           // Number of reachable positions in current window.

        for (int i = 1; i < n; ++i) {
            // When index (i - minJump) enters the window, add its reachability.
            if (i - minJump >= 0)
                pre += dp[i - minJump];

            // When index (i - maxJump - 1) leaves the window, subtract its reachability.
            if (i - maxJump - 1 >= 0)
                pre -= dp[i - maxJump - 1];

            // Current index is reachable if:
            // 1) It is '0' (we are allowed to stand here), and
            // 2) There is at least one reachable index in [i - maxJump, i - minJump].
            dp[i] = (pre > 0) && (s[i] == '0');
        }

        return dp[n - 1];
    }
};
