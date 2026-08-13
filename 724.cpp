class Solution {
    struct Node {
        char lc, rc;
        int len, pref, suff, best;
    };

    vector<Node> seg;
    string s;

    Node merge(const Node& left, const Node& right) {
        Node cur;
        cur.lc = left.lc;
        cur.rc = right.rc;
        cur.len = left.len + right.len;

        cur.pref = left.pref;
        if (left.pref == left.len && left.rc == right.lc) {
            cur.pref = left.len + right.pref;
        }

        cur.suff = right.suff;
        if (right.suff == right.len && left.rc == right.lc) {
            cur.suff = right.len + left.suff;
        }

        cur.best = max(left.best, right.best);
        if (left.rc == right.lc) {
            cur.best = max(cur.best, left.suff + right.pref);
        }

        return cur;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[idx] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        int n = s.size();

        seg.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queryCharacters.size());

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
