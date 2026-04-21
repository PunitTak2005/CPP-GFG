class Solution {
public:
    struct DSU {
        vector<int> p, r;
        DSU(int n) : p(n), r(n, 0) {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]);
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
        }
    };

    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // 1. Build components via union-find
        for (auto &e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        // 2. For each component root, collect indices
        unordered_map<int, vector<int>> comp;  // root -> indices
        comp.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            comp[dsu.find(i)].push_back(i);
        }

        int ans = 0;

        // 3. For each component, count frequency of values in source and target
        for (auto &kv : comp) {
            auto &idx = kv.second;

            unordered_map<int, int> cnt;
            cnt.reserve(idx.size() * 2);

            // count from source
            for (int i : idx) {
                cnt[source[i]]++;
            }
            // match with target
            for (int i : idx) {
                auto it = cnt.find(target[i]);
                if (it != cnt.end() && it->second > 0) {
                    it->second--;
                } else {
                    ans++;  // this position cannot be matched within the component
                }
            }
        }
        return ans;
    }
};
