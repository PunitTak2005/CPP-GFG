class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // Work on a dynamic copy
        vector<int> v = nums;
        int n = v.size();
        if (n <= 1) return 0;

        auto isNonDecreasing = [&](const vector<int>& a) {
            for (int i = 1; i < (int)a.size(); ++i)
                if (a[i] < a[i - 1]) return false;
            return true;
        };

        int ops = 0;

        while (!isNonDecreasing(v)) {
            int m = v.size();
            // Find leftmost adjacent pair with minimum sum
            int minSum = v[0] + v[1];
            int idx = 0;
            for (int i = 1; i + 1 < m; ++i) {
                int s = v[i] + v[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;            // keep the leftmost minimum
                }
            }
            // Merge the pair at idx and idx+1 into their sum
            int sum = v[idx] + v[idx + 1];
            v[idx] = sum;
            v.erase(v.begin() + idx + 1);
            ++ops;
        }

        return ops;
    }
};
