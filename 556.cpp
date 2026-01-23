class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Work on long long copy
        vector<long long> a(nums.begin(), nums.end());
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        // Min-heap: (sum, leftIndex)
        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i + 1 < n; ++i) {
            pq.push({a[i] + a[i + 1], i});
        }

        // decreaseCount = number of decreasing adjacent pairs
        int decreaseCount = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) ++decreaseCount;
        }

        auto isDec = [&](int i, int j) {
            if (i == -1 || j == -1) return false;
            return a[i] > a[j];
        };

        int ops = 0;

        while (decreaseCount > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = right[i];
            // lazy deletion: check validity and unchanged sum
            if (j == -1 || !alive[i] || !alive[j] || a[i] + a[j] != sum) {
                continue;
            }

            int L = left[i];
            int R = right[j];

            // remove old decreasing edges
            if (isDec(L, i)) --decreaseCount;
            if (isDec(i, j)) --decreaseCount;
            if (isDec(j, R)) --decreaseCount;

            // merge j into i
            a[i] = sum;
            alive[j] = false;

            // relink
            right[i] = R;
            if (R != -1) left[R] = i;

            // add new decreasing edges
            if (isDec(L, i)) ++decreaseCount;
            if (isDec(i, R)) ++decreaseCount;

            // push new adjacent sums
            if (L != -1) pq.push({a[L] + a[i], L});
            if (R != -1) pq.push({a[i] + a[R], i});

            ++ops;
        }

        return ops;
    }
};
