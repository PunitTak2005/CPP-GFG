class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        // Min-heap: (finish time, server id)
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // Available servers, kept in sorted order
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> handled(k, 0);

        for (int i = 0; i < n; i++) {
            long long start = arrival[i];
            long long finish = start + (long long)load[i];

            // Free every server whose job has finished by now
            while (!busy.empty() && busy.top().first <= start) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue; // request is dropped
            }

            int preferred = i % k;

            // Find first available server at or after preferred
            auto it = available.lower_bound(preferred);

            // If none, wrap around to the smallest available server
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            available.erase(it);

            handled[server]++;
            busy.push({finish, server});
        }

        int maxHandled = *max_element(handled.begin(), handled.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (handled[i] == maxHandled) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
