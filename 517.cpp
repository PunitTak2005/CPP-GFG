class Solution {
public:
    struct DSU {
        vector<int> parent, sz;

        DSU(int n) : parent(n + 1), sz(n + 1, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // 1) Build components using DSU
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            dsu.unite(u, v);
        }

        // 2) For each station, find its component root
        vector<int> root(c + 1);
        for (int i = 1; i <= c; ++i) {
            root[i] = dsu.find(i);
        }

        // 3) For each component root, keep a set of online stations (sorted)
        unordered_map<int, set<int>> compSet;
        compSet.reserve(c * 2);

        vector<bool> online(c + 1, true);
        for (int i = 1; i <= c; ++i) {
            int r = root[i];
            compSet[r].insert(i);
        }

        // 4) Process queries
        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int type = q[0];
            int x    = q[1];

            if (type == 2) {
                // Station x goes offline
                if (online[x]) {
                    online[x] = false;
                    int r = root[x];
                    auto itComp = compSet.find(r);
                    if (itComp != compSet.end()) {
                        itComp->second.erase(x);  // erase if present
                    }
                }
            } else { // type == 1
                int r = root[x];
                auto itComp = compSet.find(r);
                if (itComp == compSet.end() || itComp->second.empty()) {
                    ans.push_back(-1);
                } else {
                    // smallest online id in this component
                    ans.push_back(*itComp->second.begin());
                }
            }
        }

        return ans;
    }
};
