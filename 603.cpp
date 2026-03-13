class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;

        // Sort so fast workers are used first (optional but safe).
        sort(workerTimes.begin(), workerTimes.end());

        auto can = [&](ll T) -> bool {
            ll total = 0;
            for (int w : workerTimes) {
                // For worker time w, we need max x such that:
                // w * (1 + 2 + ... + x) = w * x * (x + 1) / 2 <= T
                // => x^2 + x - 2*T / w <= 0
                // Solve with quadratic formula: x = floor( (-1 + sqrt(1 + 8*T/w)) / 2 )
                long double val = (long double)T * 2.0L / (long double)w + 0.25L;
                long long x = (long long)(sqrtl(val) - 0.5L);
                if (x <= 0) continue;
                total += x;
                if (total >= mountainHeight) return true; // early stop
            }
            return total >= mountainHeight;
        };

        ll lo = 0, hi = 1;
        // Increase hi until it's enough
        while (!can(hi)) {
            hi *= 2;
        }

        ll ans = hi;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
