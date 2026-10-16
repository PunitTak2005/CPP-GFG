class Solution {
    struct Node {
        long long sum = 0;      // sum of distinct counts in range
        long long sumSq = 0;    // sum of squares of distinct counts
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;
    const int MOD = 1'000'000'007;

    void build(int node, int l, int r) {
        tree[node] = Node();
        if (l == r) return;
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
    }

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;
        tree[node].sumSq = (tree[node].sumSq
            + 2 * x % MOD * tree[node].sum % MOD
            + len % MOD * (x * x % MOD) % MOD) % MOD;

        tree[node].sum = (tree[node].sum + len % MOD * x) % MOD;
        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;
        int mid = (l + r) / 2;
        apply(2 * node, l, mid, tree[node].lazy);
        apply(2 * node + 1, mid + 1, r, tree[node].lazy);
        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long x) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, x);
        update(2 * node + 1, mid + 1, r, ql, qr, x);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sumSq = (tree[2 * node].sumSq + tree[2 * node + 1].sumSq) % MOD;
    }

    long long querySumSq(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node].sumSq;
        push(node, l, r);
        int mid = (l + r) / 2;
        return (querySumSq(2 * node, l, mid, ql, qr)
              + querySumSq(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            // For every start j in (prev, i], nums[j..i] gains one new distinct value.
            update(1, 0, n - 1, prev + 1, i, 1);

            ans = (ans + querySumSq(1, 0, n - 1, 0, i)) % MOD;
            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
