class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1'000'000'007LL;

        vector<long long> h = {1}, v = {1};
        h.insert(h.end(), hFences.begin(), hFences.end());
        v.insert(v.end(), vFences.begin(), vFences.end());
        h.push_back(m);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<long long> hDist, vDist;
        int H = h.size(), V = v.size();

        for (int i = 0; i < H; ++i) {
            for (int j = i + 1; j < H; ++j) {
                hDist.insert(h[j] - h[i]);
            }
        }

        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                vDist.insert(v[j] - v[i]);
            }
        }

        unordered_set<long long>* small = &hDist;
        unordered_set<long long>* large = &vDist;
        if (hDist.size() > vDist.size()) swap(small, large);

        long long best = -1;
        for (long long d : *small) {
            if (large->count(d)) best = max(best, d);
        }

        if (best == -1) return -1;
        long long area = (best % MOD) * (best % MOD) % MOD;
        return (int)area;
    }
};
