class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        // Calculate minimum cost
        int minCost = 0;
        int i = 0, remaining = n;
        while (i < remaining) {
            minCost += prices[i];
            i++;
            remaining -= k;
        }

        // Calculate maximum cost
        int maxCost = 0;
        int j = n - 1, index = -1;
        while (j > index) {
            maxCost += prices[j];
            j--;
            index += k;
        }

        return {minCost, maxCost};
    }
};
