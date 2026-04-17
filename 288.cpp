class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last_pos;
        last_pos.reserve(n * 2);
        last_pos.max_load_factor(0.7);

        auto rev = [&](int x) -> int {
            long long r = 0;
            while (x > 0) {
                r = r * 10 + x % 10;
                x /= 10;
            }
            return (int)r;
        };

        const int INF = 1e9;
        int ans = INF;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];

            // Step 1: if we've seen a matching reverse before, update answer
            auto it = last_pos.find(x);
            if (it != last_pos.end()) {
                ans = min(ans, i - it->second);  // i > it->second
            }

            // Step 2: store current index under key reverse(nums[i])
            int rv = rev(x);
            last_pos[rv] = i;
        }

        return ans == INF ? -1 : ans;
    }
};
