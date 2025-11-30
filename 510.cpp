class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) {
            total += x;
        }
        int rem = total % p;
        if (rem == 0) return 0; // already divisible

        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;                 // prefix remainder -> earliest index

        long long prefix = 0;
        int ans = n;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int need = (int)((prefix - rem + p) % p);  // remainder we want to see before i

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            // store / update latest index for this remainder
            mp[(int)prefix] = i;
        }

        return ans == n ? -1 : ans;  // cannot remove whole array
    }
};
