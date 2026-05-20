class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        int n = arr.size();
        unordered_set<long long> seen;

        // Special handling when target = 0
        if (target == 0) {
            int zeroCount = 0;
            bool hasNonZero = false;

            for (long long x : arr) {
                if (x == 0) {
                    zeroCount++;
                    if (zeroCount >= 2) return true;   // 0 * 0 = 0
                } else {
                    hasNonZero = true;
                }
            }
            // One zero and at least one non-zero => 0 * nonzero = 0
            return zeroCount >= 1 && hasNonZero;
        }

        // General case: target != 0
        for (long long x : arr) {
            if (x != 0 && target % x == 0) { // x must divide target
                long long need = target / x;
                if (seen.count(need)) {
                    return true;
                }
            }
            // Add current element to set after check
            seen.insert(x);
        }
        return false;
    }
};
