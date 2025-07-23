class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        // Calculate max time for ants moving left
        for (int num : left) {
            ans = max(ans, num);
        }

        // Calculate max time for ants moving right
        for (int num : right) {
            ans = max(ans, n - num);
        }

        return ans;
    }
};
