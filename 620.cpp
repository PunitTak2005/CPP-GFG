class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;
        
        long long hold = -1LL * arr[0]; // profit if we end day 0 holding
        long long notHold = 0;          // profit if we end day 0 not holding
        
        for (int i = 1; i < n; i++) {
            long long newHold = max(hold, notHold - arr[i]);        // buy or keep holding
            long long newNotHold = max(notHold, hold + arr[i] - k); // sell or keep not holding
            hold = newHold;
            notHold = newNotHold;
        }
        
        return (int)notHold;
    }
};
