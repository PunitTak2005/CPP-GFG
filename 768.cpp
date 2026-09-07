class Solution {
public:
    int n;
    int dp[101][102][102];

    int solve(int i, int inc, int dec, vector<int>& arr) {
        if (i == n) return 0;

        int &ans = dp[i][inc][dec];
        if (ans != -1) return ans;

        int x = arr[i];

        // Option 1: Do not use current element
        ans = solve(i + 1, inc, dec, arr);

        // Option 2: Add to strictly increasing subsequence
        // inc = 0 means increasing subsequence is still empty
        if (inc == 0 || x > inc) {
            ans = max(ans, 1 + solve(i + 1, x, dec, arr));
        }

        // Option 3: Add to strictly decreasing subsequence
        // dec = 101 means decreasing subsequence is still empty
        if (dec == 101 || x < dec) {
            ans = max(ans, 1 + solve(i + 1, inc, x, arr));
        }

        return ans;
    }

    int minCount(vector<int>& arr) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));

        int maximumUsed = solve(0, 0, 101, arr);
        return n - maximumUsed;
    }
};
