class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int hold = -arr[0], sold = 0, rest = 0;
        for (int i = 1; i < n; ++i) {
            int prev_hold = hold, prev_sold = sold, prev_rest = rest;
            hold = max(prev_hold, prev_rest - arr[i]);
            sold = prev_hold + arr[i];
            rest = max(prev_rest, prev_sold);
        }
        return max(sold, rest);
    }
};
