class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort the cutting costs in ascending order
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int hCount = 1, vCount = 1;
        int i = x.size() - 1, j = y.size() - 1;
        int totalCost = 0;

        while (i >= 0 && j >= 0) {

            // Choose the larger cost cut to
            // minimize future costs
            if (x[i] >= y[j]) {
                totalCost += x[i] * hCount;
                vCount++;
                i--;
            } else {
                totalCost += y[j] * vCount;
                hCount++;
                j--;
            }
        }

        // Process remaining vertical cuts
        while (i >= 0) {
            totalCost += x[i] * hCount;
            vCount++;
            i--;
        }

        // Process remaining horizontal cuts
        while (j >= 0) {
            totalCost += y[j] * vCount;
            hCount++;
            j--;
        }

        return totalCost;
    }
};

