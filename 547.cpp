class Solution {
public:
    struct Node {
        int cover = 0;
        long long len = 0;
    };

    vector<long long> xs;
    vector<Node> seg;

    void pull(int idx, int l, int r) {
        if (seg[idx].cover > 0) {
            seg[idx].len = xs[r + 1] - xs[l];
        } else if (l == r) {
            seg[idx].len = 0;
        } else {
            seg[idx].len = seg[idx * 2].len + seg[idx * 2 + 1].len;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            seg[idx].cover += val;
            pull(idx, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);
        pull(idx, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        xs.clear();
        xs.reserve(2 * n);
        for (auto &s : squares) {
            long long x1 = s[0];
            long long x2 = (long long)s[0] + s[2];
            xs.push_back(x1);
            xs.push_back(x2);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int m = (int)xs.size();
        if (m <= 1) return 0.0;

        struct Event {
            long long y;
            int type;
            int l, r;
        };
        vector<Event> ev;
        ev.reserve(2 * n);
        for (auto &s : squares) {
            long long x1 = s[0];
            long long x2 = (long long)s[0] + s[2];
            long long y1 = s[1];
            long long y2 = (long long)s[1] + s[2];
            int xl = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
            int xr = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();
            if (xl < xr) {
                ev.push_back({y1, +1, xl, xr - 1});
                ev.push_back({y2, -1, xl, xr - 1});
            }
        }
        if (ev.empty()) return 0.0;
        sort(ev.begin(), ev.end(), [](const Event& a, const Event& b) {
            return a.y < b.y;
        });

        seg.assign(4 * m, Node());

        auto sweepTotalArea = [&]() -> long double {
            long double area = 0;
            long long prevY = ev[0].y;
            int i = 0;
            while (i < (int)ev.size()) {
                long long currY = ev[i].y;
                long long dy = currY - prevY;
                if (dy > 0) {
                    long long width = seg[1].len;
                    if (width > 0) {
                        area += (long double)width * (long double)dy;
                    }
                    prevY = currY;
                }
                while (i < (int)ev.size() && ev[i].y == currY) {
                    update(1, 0, m - 2, ev[i].l, ev[i].r, ev[i].type);
                    ++i;
                }
            }
            return area;
        };

        long double totalArea = sweepTotalArea();
        long double half = totalArea / 2.0L;

        // reset segtree
        seg.assign(4 * m, Node());

        auto sweepUntilHalf = [&](long double targetHalf) -> long double {
            long double area = 0;
            long long prevY = ev[0].y;
            int i = 0;
            while (i < (int)ev.size()) {
                long long currY = ev[i].y;
                long long dy = currY - prevY;
                if (dy > 0) {
                    long long width = seg[1].len;
                    if (width > 0) {
                        long double add = (long double)width * (long double)dy;
                        if (area + add >= targetHalf) {
                            long double need = targetHalf - area;
                            long double y = prevY + need / (long double)width;
                            return y;
                        }
                        area += add;
                    }
                    prevY = currY;
                }
                while (i < (int)ev.size() && ev[i].y == currY) {
                    update(1, 0, m - 2, ev[i].l, ev[i].r, ev[i].type);
                    ++i;
                }
            }
            // theoretically should not reach here
            return (long double)ev.back().y;
        };

        long double ansY = sweepUntilHalf(half);
        return (double)ansY;
    }
};
