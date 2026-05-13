class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int m = n / 2;

        // We will use difference array of size 2 * limit + 2 (1-based sums up to 2*limit)
        vector<int> diff(2 * limit + 2, 0);

        /*
            For each pair (a, b) = (nums[i], nums[n-1-i]):

            Initially assume worst case: 2 moves for every possible sum in [2, 2*limit].
            Then we "refund" moves where 1 or 0 moves are sufficient using a sweep line:

            - For all sums in [2, 2*limit], cost starts at +2.

            - Range where we can do it in at most 1 move:
              [min(a, b) + 1, max(a, b) + limit]
              For these sums, cost decreases by 1 (2 -> 1).

            - Exact sum where we need 0 moves: s0 = a + b
              For this single sum, cost further decreases by 1 (1 -> 0).

            Implementation using diff (prefix sums later):
              cost[x] = base 0, then we add contributions of each pair:
                +2 for all sums
                -1 on [min+1, max+limit]
                -1 at s0
        */

        // We first add +2 for all sums by starting with a baseline "pairs * 2",
        // and then adjust using diff for -1 and -1 updates.
        // Instead of actually adding +2 to every index, we’ll interpret prefix sum
        // as "extra moves beyond baseline", then final cost = baseline + prefix.
        // Concretely: diff will store adjustments relative to 2*m.
        for (int i = 0; i < m; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            if (a > b) swap(a, b);

            int low = a + 1;
            int high = b + limit;
            int s0 = a + b;

            // For [low, high], cost-- (2 -> 1)
            diff[low] -= 1;
            diff[high + 1] += 1;

            // For exact s0, cost-- again (1 -> 0)
            diff[s0] -= 1;
            diff[s0 + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;
        // Evaluate cost for every possible target sum t in [2, 2*limit]
        for (int t = 2; t <= 2 * limit; ++t) {
            cur += diff[t];
            // baseline is 2 moves per pair
            int moves = 2 * m + cur;
            ans = min(ans, moves);
        }

        return ans;
    }
};
