class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // Sort by start time
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        
        // Suffix max of values: best single event starting at or after i
        vector<int> suffixMax(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        
        long long ans = 0;
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) starts[i] = events[i][0];
        
        for (int i = 0; i < n; ++i) {
            long long cur = events[i][2];
            int endTime = events[i][1];
            
            // first event with start >= endTime + 1 (non-overlapping, since inclusive)
            int idx = lower_bound(starts.begin(), starts.end(), endTime + 1) - starts.begin();
            if (idx < n) cur += suffixMax[idx];
            
            ans = max(ans, cur);
        }
        
        return (int)ans;
    }
};
