class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by start ascending; if start is equal, sort by end descending
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        int count = 0;
        int curStart = -1;
        int curEnd = -1;

        for (const auto& in : intervals) {
            int s = in[0];
            int e = in[1];

            // If current interval is covered by [curStart, curEnd], skip it
            if (curStart <= s && e <= curEnd) {
                continue;
            }

            // Otherwise, this is a new remaining interval
            count++;
            curStart = s;
            curEnd = e;
        }

        return count;
    }
};
