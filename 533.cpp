class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());  // sort by start time

        // freeRooms: min-heap of available room indices
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        // busyRooms: (endTime, roomIdx), min by endTime then roomIdx
        using ll = long long;
        priority_queue<
            pair<ll,int>,
            vector<pair<ll,int>>,
            greater<pair<ll,int>>
        > busyRooms;

        vector<long long> cnt(n, 0);

        for (auto &m : meetings) {
            ll start = m[0];
            ll end   = m[1];
            ll dur   = end - start;  // duration

            // free all rooms whose meeting ends on or before current start
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(room);
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                cnt[room]++;
                busyRooms.push({start + dur, room});
            } else {
                auto [endTime, room] = busyRooms.top();
                busyRooms.pop();
                cnt[room]++;
                busyRooms.push({endTime + dur, room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (cnt[i] > cnt[ans]) ans = i;
        }
        return ans;
    }
};
