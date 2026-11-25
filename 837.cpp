#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1) return 1;

        static constexpr uint64_t BASE1 = 1000003ULL;
        static constexpr uint64_t MOD1  = 1000000007ULL;
        static constexpr uint64_t BASE2 = 1000033ULL;
        static constexpr uint64_t MOD2  = 1000000009ULL;

        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<uint64_t> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            uint64_t val = static_cast<uint64_t>(nums[i]);
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2;

            pref1[i + 1] = (pref1[i] * BASE1 + val) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE2 + val) % MOD2;
        }

        auto getHash = [&](int l, int r) -> uint64_t {
            int len = r - l + 1;
            uint64_t h1 = (pref1[r + 1] + MOD1 - (pref1[l] * pow1[len]) % MOD1) % MOD1;
            uint64_t h2 = (pref2[r + 1] + MOD2 - (pref2[l] * pow2[len]) % MOD2) % MOD2;
            return (h1 << 32) | h2;
        };

        auto hasUniqueOfLen = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);

            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;
                ++freq[getHash(l, r)];
            }

            for (const auto& [_, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLen(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
