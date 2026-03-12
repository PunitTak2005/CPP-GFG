class DSU {
public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int maxS = 0;
        for (auto &e : edges) {
            maxS = max(maxS, e[2] * 2); // since we can double
        }

        auto can = [&](int X) -> bool {
            DSU dsu(n);
            long long usedEdges = 0;
            int upgradesLeft = k;

            // First process mandatory edges (musti == 1)
            for (auto &e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if (must == 1) {
                    if (s < X) return false;              // cannot reach X
                    if (!dsu.unite(u, v)) return false;   // cycle among must-edges
                    ++usedEdges;
                }
            }

            // Collect optional edges (musti == 0) and sort by strength descending
            vector<array<int, 3>> opt;
            opt.reserve(edges.size());
            for (auto &e : edges) {
                if (e[3] == 0) {
                    opt.push_back({e[2], e[0], e[1]});
                }
            }
            sort(opt.begin(), opt.end(),
                 [](const auto &a, const auto &b) { return a[0] > b[0]; });

            for (auto &e : opt) {
                if (usedEdges == n - 1) break;
                int s = e[0], u = e[1], v = e[2];
                int fu = dsu.find(u), fv = dsu.find(v);
                if (fu == fv) continue;

                if (s >= X) {
                    dsu.unite(fu, fv);
                    ++usedEdges;
                } else if (1LL * s * 2 >= X && upgradesLeft > 0) {
                    dsu.unite(fu, fv);
                    ++usedEdges;
                    --upgradesLeft;
                }
            }

            return usedEdges == n - 1;
        };

        int lo = 1, hi = maxS, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
