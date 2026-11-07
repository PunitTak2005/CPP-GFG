class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);

        // (weight, server index)
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > freeServers;

        // (free time, weight, server index)
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busyServers;

        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }

        long long time = 0;

        for (int j = 0; j < m; ++j) {
            // A task cannot start before it arrives.
            time = max(time, (long long)j);

            // Release every server that has become free by 'time'.
            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= time) {
                auto [freeTime, weight, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, idx});
            }

            // All servers are busy: wait for the earliest release time.
            if (freeServers.empty()) {
                time = get<0>(busyServers.top());

                while (!busyServers.empty() &&
                       get<0>(busyServers.top()) <= time) {
                    auto [freeTime, weight, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({weight, idx});
                }
            }

            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({time + tasks[j], weight, idx});
        }

        return ans;
    }
};
