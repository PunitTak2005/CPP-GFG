class Solution {
public:
    struct ZeroGroup {
        int start, end, length;
    };

    // Sparse table for range max
    struct SparseTable {
        int n;
        vector<int> log2v;
        vector<vector<int>> st;
        SparseTable() {}
        SparseTable(const vector<int>& a) { build(a); }

        void build(const vector<int>& a) {
            n = (int)a.size();
            if (!n) return;
            log2v.assign(n + 1, 0);
            for (int i = 2; i <= n; ++i)
                log2v[i] = log2v[i / 2] + 1;
            int K = log2v[n] + 1;
            st.assign(K, vector<int>(n));
            st[0] = a;
            for (int k = 1; k < K; ++k) {
                for (int i = 0; i + (1 << k) <= n; ++i) {
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        // query max on [l, r]
        int query(int l, int r) const {
            if (l > r) return INT_MIN;
            int len = r - l + 1;
            int k = log2v[len];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = (int)s.size();

        // total ones in whole string
        int ones = 0;
        for (char c : s) if (c == '1') ++ones;

        // Build zero groups (maximal runs of '0')
        vector<ZeroGroup> zeroGroups;
        vector<int> zeroGroupIndex(n, -1); // for each position, which zero group it belongs to
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') ++j;
                int idx = (int)zeroGroups.size();
                zeroGroups.push_back({i, j - 1, j - i});
                for (int k = i; k < j; ++k) zeroGroupIndex[k] = idx;
                i = j;
            } else {
                ++i;
            }
        }

        // If no zeros, you can never gain anything; every query answer is total ones
        if (zeroGroups.empty()) {
            vector<int> ans(queries.size(), ones);
            return ans;
        }

        int m = (int)zeroGroups.size();

        // Build "adjacent group length sums":
        // idea: each zero group that is surrounded by ones contributes
        // leftOnes + zeroLen + rightOnes (as potential gain) in some mapping.
        // The official solutions compress this; we follow similar pattern. [web:6][web:7]

        // Precompute length of left/right 1-runs next to each zero-group
        vector<int> leftOnes(n), rightOnes(n);
        // leftOnes[i] = length of consecutive ones ending at i
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                leftOnes[i] = (i ? leftOnes[i - 1] : 0) + 1;
            else
                leftOnes[i] = 0;
        }
        // rightOnes[i] = length of consecutive ones starting at i
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1')
                rightOnes[i] = (i + 1 < n ? rightOnes[i + 1] : 0) + 1;
            else
                rightOnes[i] = 0;
        }

        // For each zero group that is strictly inside ones (i.e., '1...0s...1'),
        // compute gain = lenZero + leftRun + rightRun.
        // We arrange these as an array to query max over ranges later. [web:6][web:7]
        vector<int> gain(m, INT_MIN);
        for (int i = 0; i < m; ++i) {
            int L = zeroGroups[i].start;
            int R = zeroGroups[i].end;
            int len0 = zeroGroups[i].length;
            int left1 = (L > 0 ? leftOnes[L - 1] : 0);
            int right1 = (R + 1 < n ? rightOnes[R + 1] : 0);
            if (left1 > 0 && right1 > 0) {
                gain[i] = len0 + left1 + right1;
            }
        }

        SparseTable st(gain);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            int best = ones;  // at least current ones, maybe we can't improve

            // We only trade inside s[l..r], but note the augmentation with '1' at both ends
            // basically means trades that touch edges behave as if they have bordering ones. [web:2]

            // Case 1: a fully contained zero-group (index range of zeroGroups intersecting [l,r])
            int firstZ = -1, lastZ = -1;
            // find first/last zero-groups that intersect [l, r]
            // (simple linear scan over indices in substring is too slow; but zeroGroupIndex gives us direct) [web:6]
            if (zeroGroupIndex[l] != -1)
                firstZ = zeroGroupIndex[l];
            else {
                int i = l + 1;
                while (i <= r && zeroGroupIndex[i] == -1) ++i;
                if (i <= r) firstZ = zeroGroupIndex[i];
            }
            if (zeroGroupIndex[r] != -1)
                lastZ = zeroGroupIndex[r];
            else {
                int i = r - 1;
                while (i >= l && zeroGroupIndex[i] == -1) --i;
                if (i >= l) lastZ = zeroGroupIndex[i];
            }

            if (firstZ != -1 && lastZ != -1 && firstZ <= lastZ) {
                // any zero group fully inside [l,r] whose gain doesn't rely on outside ones is candidate
                // approximate: query st over [firstZ, lastZ]
                int mx = st.query(firstZ, lastZ);
                if (mx != INT_MIN)
                    best = max(best, ones + mx);
            }

            // Case 2: zero-run starting in l or ending in r may partially lie outside query,
            // but due to virtual ones at edges, you can sometimes treat them as fully surrounded. [web:2][web:7]
            // We try to extend left/right gains locally.

            // extend from left border if s[l] == '0'
            if (s[l] == '0') {
                int gIdx = zeroGroupIndex[l];
                int L = zeroGroups[gIdx].start;
                int R = zeroGroups[gIdx].end;
                int lenInside = min(R, r) - l + 1;
                // augmented left '1' gives extra leftOnes = 1
                int right1 = (R + 1 <= r ? rightOnes[R + 1] : 0);
                int gainBorder = lenInside + 1 + right1;
                best = max(best, ones + gainBorder);
            }

            // extend from right border if s[r] == '0'
            if (s[r] == '0') {
                int gIdx = zeroGroupIndex[r];
                int L = zeroGroups[gIdx].start;
                int R = zeroGroups[gIdx].end;
                int lenInside = r - max(L, l) + 1;
                // augmented right '1'
                int left1 = (L - 1 >= l ? leftOnes[L - 1] : 0);
                int gainBorder = lenInside + 1 + left1;
                best = max(best, ones + gainBorder);
            }

            ans.push_back(best);
        }

        return ans;
    }
};
