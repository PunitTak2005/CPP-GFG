class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        deque<int> dq;                 // indices, nums[dq] non-increasing
        int right = n - 1;

        for (int left = n - 1; left >= 0; --left) {
            int num = nums[left];
            int count = 1;

            // Raise smaller adjusted values on the right to `num`
            while (!dq.empty() && nums[dq.back()] < num) {
                int idx = dq.back();
                dq.pop_back();

                int nextPos = dq.empty() ? right + 1 : dq.back();
                cost += 1LL * (nextPos - idx) * (num - nums[idx]);
                count += nextPos - idx;
            }

            dq.push_back(left);

            // Shrink from the right while over budget
            while (cost > k) {
                cost -= 1LL * (nums[dq.front()] - nums[right]);
                if (dq.front() == right) dq.pop_front();
                --right;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
