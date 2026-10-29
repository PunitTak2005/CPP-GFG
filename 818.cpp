class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy, head, pos;
    vector<int> tree;
    int timer = 0;

    void add(int i, int val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] ^ tree[i ^ 1];
    }

    int query(int l, int r) { // inclusive
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res ^= tree[l++];
            if (r & 1) res ^= tree[--r];
        }
        return res;
    }

    void dfsSize(int root) {
        vector<int> order;
        vector<int> stk = {root};
        parent[root] = -1;

        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stk.push_back(v);
            }
        }

        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int u = order[i];
            sz[u] = 1;
            heavy[u] = -1;

            int best = 0;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                sz[u] += sz[v];
                if (sz[v] > best) {
                    best = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void decompose(int root) {
        vector<int> stk = {root};

        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();

            for (int v = u; v != -1; v = heavy[v]) {
                head[v] = u; // FIX: head of this heavy chain is u
                pos[v] = timer++;

                for (int w : adj[v]) {
                    if (w != parent[v] && w != heavy[v]) {
                        stk.push_back(w);
                    }
                }
            }
        }
    }

    int pathQuery(int u, int v) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) {
                swap(u, v);
            }
            res ^= query(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        res ^= query(pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        n = n_;
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 1);
        heavy.assign(n, -1);
        head.assign(n, -1);
        pos.assign(n, -1);
        tree.assign(2 * n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsSize(0);
        decompose(0);

        for (int u = 0; u < n; ++u) {
            add(pos[u], 1 << (s[u] - 'a'));
        }

        vector<bool> ans;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ');
                int space2 = q.find(' ', space1 + 1);

                int u = stoi(q.substr(space1 + 1, space2 - space1 - 1));
                char c = q.back();

                add(pos[u], 1 << (c - 'a'));
            } else {
                int space1 = q.find(' ', 6);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));

                int mask = pathQuery(u, v);
                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};
