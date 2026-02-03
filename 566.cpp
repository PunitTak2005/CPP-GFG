class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        // inc[i] = nums[0..i] strictly increasing
        vector<bool> inc(n, false);
        inc[0] = true;
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i - 1] && (nums[i - 1] < nums[i]);
        }

        // inc2[i] = nums[i..n-1] strictly increasing
        vector<bool> inc2(n, false);
        inc2[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            inc2[i] = inc2[i + 1] && (nums[i] < nums[i + 1]);
        }

        // try all p, q with 0 < p < q < n-1
        for (int p = 1; p <= n - 3; ++p) {
            if (!inc[p]) continue;  // first part must be strictly increasing

            for (int q = p + 1; q <= n - 2; ++q) {
                if (!inc2[q]) continue;  // last part must be strictly increasing

                // check middle part nums[p..q] strictly decreasing
                bool ok = true;
                for (int i = p; i < q; ++i) {
                    if (!(nums[i] > nums[i + 1])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return true;
            }
        }

        return false;
    }
};
