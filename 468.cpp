#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Function to check if subarray [start, start + k - 1] is strictly increasing
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        // Loop through possible starting points for the first subarray
        for (int i = 0; i + 2 * k <= n; i++) {
            int j = i + k; // adjacent subarray starts here
            if (isIncreasing(i) && isIncreasing(j)) {
                return true;
            }
        }

        return false;
    }
};
