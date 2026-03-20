class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int H = m - k + 1, W = n - k + 1;
        vector<vector<int>> ans(H, vector<int>(W, 0));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                vector<int> nums;
                nums.reserve(k * k);

                // collect all elements in current k x k submatrix
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        nums.push_back(grid[i + x][j + y]);
                    }
                }

                sort(nums.begin(), nums.end());

                int best = INT_MAX;
                // scan consecutive distinct elements
                for (int p = 1; p < (int)nums.size(); ++p) {
                    if (nums[p] != nums[p - 1]) {
                        best = min(best, nums[p] - nums[p - 1]);
                    }
                }

                // if all equal, answer is 0, otherwise best
                ans[i][j] = (best == INT_MAX ? 0 : best);
            }
        }
        return ans;
    }
};
