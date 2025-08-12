class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int need = (n + 1) / 2;
        vector<int> costs;

        for (int num : arr) {
            if (num % k == 0) {
                costs.push_back(0);
            } else {
                costs.push_back(k - (num % k));
            }
        }

        // Sort the costs in ascending order
        sort(costs.begin(), costs.end());

        // Add up the smallest `need` costs
        int total = 0;
        for (int i = 0; i < need; ++i) {
            total += costs[i];
        }

        return total;
    }
};
