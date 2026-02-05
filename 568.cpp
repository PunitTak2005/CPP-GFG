class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                long long steps = nums[i];
                long long idx = i + steps;          // move right for +ve, left for -ve
                // normalize to [0, n-1]
                idx %= n;                           // in C++ negative % stays negative
                if (idx < 0) idx += n;
                result[i] = nums[idx];
            }
        }

        return result;
    }
};
