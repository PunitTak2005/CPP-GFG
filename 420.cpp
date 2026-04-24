class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int maxH = INT_MIN;

        for (int i = 0; i < n; ++i) {
            // building receives sunlight if its height is
            // >= max height so far (not lesser than any to its left)
            if (arr[i] >= maxH) {
                ++cnt;
                maxH = arr[i];
            }
        }
        return cnt;
    }
};
