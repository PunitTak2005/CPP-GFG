class Solution {
public:
    struct SegTree {
        struct Node { 
            int mn, mx, lazy; 
        };
        int n;
        vector<Node> st;

        SegTree(int n) : n(n), st(4 * n, {0, 0, 0}) {}

        void apply(int p, int val) {
            st[p].mn += val;
            st[p].mx += val;
            st[p].lazy += val;
        }

        void push(int p) {
            if (st[p].lazy != 0) {
                apply(p << 1, st[p].lazy);
                apply(p << 1 | 1, st[p].lazy);
                st[p].lazy = 0;
            }
        }

        void pull(int p) {
            st[p].mn = min(st[p << 1].mn, st[p << 1 | 1].mn);
            st[p].mx = max(st[p << 1].mx, st[p << 1 | 1].mx);
        }

        void range_add(int p, int l, int r, int ql, int qr, int val) {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                apply(p, val);
                return;
            }
            push(p);
            int m = (l + r) >> 1;
            range_add(p << 1, l, m, ql, qr, val);
            range_add(p << 1 | 1, m + 1, r, ql, qr, val);
            pull(p);
        }

        int first_zero(int p, int l, int r, int ql, int qr) {
            // PRUNING: If 0 is not in [mn, mx], it cannot exist in this subtree
            if (ql > r || qr < l || st[p].mn > 0 || st[p].mx < 0) return -1;
            if (l == r) return (st[p].mn == 0) ? l : -1;

            push(p);
            int m = (l + r) >> 1;
            int res = first_zero(p << 1, l, m, ql, qr);
            if (res != -1) return res;
            return first_zero(p << 1 | 1, m + 1, r, ql, qr);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegTree st(n);
        // Using a fixed-size array instead of unordered_map for O(1) speed
        vector<int> last(100001, -1);
        int ans = 0;

        for (int r = 0; r < n; ++r) {
            int x = nums[r];
            int sign = (x & 1) ? 1 : -1;

            int prev_idx = last[x];
            // x contributes its sign only from the index after its last appearance
            st.range_add(1, 0, n - 1, prev_idx + 1, r, sign);
            last[x] = r;

            // Search for the earliest (leftmost) index l where balance is 0
            int l = st.first_zero(1, 0, n - 1, 0, r);
            if (l != -1) {
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};
