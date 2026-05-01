class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate sum of all elements
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // Calculate F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        int f = 0;
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        
        // Initialize max with F(0)
        int maxF = f;
        
        // Calculate F(1), F(2), ..., F(n-1) using the recurrence relation
        for (int i = 1; i < n; i++) {
            // F(i) = F(i-1) + sum - n * nums[n-i]
            f = f + sum - n * nums[n - i];
            maxF = max(maxF, f);
        }
        
        return maxF;
    }
};
