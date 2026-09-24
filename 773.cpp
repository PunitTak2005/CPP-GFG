class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        vector<pair<int,int>> discs;
        discs.reserve(n);

        vector<int> allH = h;
        for (int i = 0; i < n; i++) discs.push_back({r[i], h[i]});

        sort(discs.begin(), discs.end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        sort(allH.begin(), allH.end());
        allH.erase(unique(allH.begin(), allH.end()), allH.end());

        auto getId = [&](int x) {
            return int(lower_bound(allH.begin(), allH.end(), x) - allH.begin()) + 1;
        };

        vector<int> bit(allH.size() + 2, 0);

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res = max(res, bit[idx]);
                idx -= idx & -idx;
            }
            return res;
        };

        auto update = [&](int idx, int val) {
            while (idx < (int)bit.size()) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };

        int ans = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            vector<pair<int,int>> tmp;

            while (j < n && discs[j].first == discs[i].first) {
                int id = getId(discs[j].second);
                int best = query(id - 1);
                tmp.push_back({id, best + discs[j].second});
                ans = max(ans, best + discs[j].second);
                j++;
            }

            for (auto &p : tmp) update(p.first, p.second);
            i = j;
        }

        return ans;
    }
};
