class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // initial people who know the secret: 0 and firstPerson
        vector<bool> know(n, false);
        know[0] = true;
        know[firstPerson] = true;

        // sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int m = meetings.size();
        int i = 0;
        while (i < m) {
            int t = meetings[i][2];

            // collect all meetings with the same time t
            vector<pair<int,int>> edges;
            unordered_set<int> persons;
            while (i < m && meetings[i][2] == t) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                edges.push_back({x, y});
                persons.insert(x);
                persons.insert(y);
                ++i;
            }

            // build adjacency list for this time group
            unordered_map<int, vector<int>> g;
            for (auto &e : edges) {
                g[e.first].push_back(e.second);
                g[e.second].push_back(e.first);
            }

            // BFS/DFS from all nodes in this group that already know the secret
            queue<int> q;
            unordered_set<int> visited;
            for (int p : persons) {
                if (know[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            // everyone reached in this component now knows the secret
            for (int p : visited) {
                know[p] = true;
            }
        }

        vector<int> ans;
        for (int p = 0; p < n; ++p) {
            if (know[p]) ans.push_back(p);
        }
        return ans;
    }
};
