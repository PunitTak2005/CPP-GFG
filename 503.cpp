class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    };

    static const int LOG = 17; // For V <= 100 (2^7 = 128)

    vector<vector<pair<int,int>>> adj;
    int up[105][LOG];              // LCA parent
    int mx[105][LOG];              // Maximum edge on path
    int depth[105];

    void dfs(int u, int p, int w) {
        up[u][0] = p;
        mx[u][0] = w;
        for (auto &x : adj[u]) {
            int v = x.first, wt = x.second;
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, wt);
        }
    }

    int getMaxEdge(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int maxEdge = 0;

        // lift u up
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                maxEdge = max(maxEdge, mx[u][i]);
                u = up[u][i];
            }
        }
        if (u == v) return maxEdge;

        // lift both
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                maxEdge = max({maxEdge, mx[u][i], mx[v][i]});
                u = up[u][i];
                v = up[v][i];
            }
        }

        return max({maxEdge, mx[u][0], mx[v][0]});
    }

    int secondMST(int V, vector<vector<int>> &edges) {
        vector<array<int,3>> e;
        for (auto &x : edges) e.push_back({x[0], x[1], x[2]});

        sort(e.begin(), e.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        DSU dsu(V);
        int mstWeight = 0;
        vector<bool> used(e.size(), false);

        int edgesUsed = 0;

        // Build MST
        for (int i = 0; i < e.size(); i++) {
            auto &[u, v, w] = e[i];
            if (dsu.unite(u, v)) {
                mstWeight += w;
                used[i] = true;
                edgesUsed++;
            }
        }

        if (edgesUsed != V - 1) return -1; // no MST possible

        // Build tree for LCA
        adj.assign(V, {});
        for (int i = 0; i < e.size(); i++) {
            if (used[i]) {
                auto &[u, v, w] = e[i];
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }

        depth[0] = 0;
        dfs(0, -1, 0);

        // Precompute LCA tables
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < V; i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                    mx[i][j] = max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);
                } else {
                    up[i][j] = -1;
                    mx[i][j] = 0;
                }
            }
        }

        // Try forming second best MST
        int ans = INT_MAX;

        for (int i = 0; i < e.size(); i++) {
            if (used[i]) continue;

            int u = e[i][0];
            int v = e[i][1];
            int w = e[i][2];

            int maxEdge = getMaxEdge(u, v);

            int newWeight = mstWeight + w - maxEdge;

            if (newWeight > mstWeight)
                ans = min(ans, newWeight);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
