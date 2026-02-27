class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int z0 = 0;
        for (char c : s) if (c == '0') ++z0;

        if (z0 == 0) return 0;                 // already all '1'
        if (k == 0) return -1;                 // cannot flip anything

        // Parity check: if k is even, zero-count parity never changes.
        if ((k % 2 == 0) && (z0 % 2 == 1)) return -1;

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        // Two ordered sets of unvisited states by parity.
        set<int> unused[2];
        for (int z = 0; z <= n; ++z) {
            unused[z & 1].insert(z);
        }

        queue<int> q;
        dist[z0] = 0;
        unused[z0 & 1].erase(z0);
        q.push(z0);

        while (!q.empty()) {
            int z = q.front();
            q.pop();
            int d = dist[z];

            if (z == 0) return d;

            // Determine range of x: number of zeros we flip in this operation.
            int Lx = max(0, k - (n - z));
            int Rx = min(k, z);
            if (Lx > Rx) continue;

            // z' = z + k - 2x, so as x increases by 1, z' decreases by 2.
            // x = Lx -> z_max, x = Rx -> z_min
            int z_max = z + k - 2 * Lx;
            int z_min = z + k - 2 * Rx;

            // All reachable z' from this state form an arithmetic progression
            // with step 2 and same parity as (z + k).
            int parity = (z + k) & 1;

            // We want all unvisited states with this parity in [z_min, z_max].
            auto &S = unused[parity];
            auto it = S.lower_bound(z_min);
            while (it != S.end() && *it <= z_max) {
                int nz = *it;
                it = S.erase(it);       // mark visited
                dist[nz] = d + 1;
                q.push(nz);
            }
        }

        return -1;
    }
};
