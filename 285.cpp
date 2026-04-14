class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int n = robot.size();
        int m = factory.size();

        // dp[i][j] = minimum distance to fix robots from i..n-1 using factories j..m-1
        // initialize with -1 (uncomputed)
        static long long dp[101][101];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = -1;

        function<long long(int,int)> solve = [&](int i, int j) -> long long {
            if (i == n) return 0;                  // all robots fixed
            if (j == m) return (long long)4e18;    // no factories left but robots remain

            long long &res = dp[i][j];
            if (res != -1) return res;

            // Option 1: skip this factory
            res = solve(i, j + 1);

            // Option 2: assign some robots to this factory
            long long distSum = 0;
            long long pos = factory[j][0];
            int cap = factory[j][1];

            // try assigning k robots (1..cap) to factory j
            for (int k = 0; k < cap && i + k < n; ++k) {
                distSum += llabs((long long)robot[i + k] - pos);
                res = min(res, distSum + solve(i + k + 1, j + 1));
            }
            return res;
        };

        return solve(0, 0);
    }
};
