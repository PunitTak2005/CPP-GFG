class Solution {
  private:
    // Returns the cost of bringing all towers to the equal height eq_h
    int costOfOperation(int n, vector<int>& heights, vector<int>& cost, int eq_h) {
        int total_cost = 0;
        for (int i = 0; i < n; i++) {
            total_cost += abs(heights[i] - eq_h) * cost[i];
        }
        return total_cost;
    }

  public:
    // Return the minimum possible cost of operation to equalize tower heights
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        int max_h = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX;

        int low = 0, high = max_h + 1;
        while (high > low) {

            int mid = low + (high - low) / 2;
            int cost_at_mid_minus_1 =
                (mid > 0) ? costOfOperation(n, heights, cost, mid - 1) : INT_MAX;
            int cost_at_mid = costOfOperation(n, heights, cost, mid);
            int cost_at_mid_plus_1 = costOfOperation(n, heights, cost, mid + 1);

            ans = min(ans, cost_at_mid);

            if (cost_at_mid_minus_1 <= cost_at_mid) {
                high = mid;
            } else if (cost_at_mid_plus_1 <= cost_at_mid) {
                low = mid + 1;
            } else {
                return cost_at_mid;
            }
        }

        return ans;
    }
};
