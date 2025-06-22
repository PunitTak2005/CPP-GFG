class Solution {
  public:
    int lds(vector<int>& arr, vector<int>& memo, vector<int>& parent, int i) {
        if (memo[i] != -1) {
            // Return previously computed result
            return memo[i];
        }

        int maxLength = 1;
        int bestParent = -1;

        // Try including arr[i] in the subset by checking all j < i
        for (int j = 0; j < i; j++) {
            if (arr[j] % arr[i] == 0) {
                int length = lds(arr, memo, parent, j) + 1;
                if (length > maxLength) {
                    maxLength = length;
                    bestParent = j;
                }
            }
        }

        memo[i] = maxLength;
        parent[i] = bestParent;
        return maxLength;
    }

    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();

        // Sort the array in descending order
        sort(arr.rbegin(), arr.rend());

        vector<int> memo(n, -1);
        vector<int> parent(n, -1);
        int maxSize = 0;
        int lastIndex = 0;

        // Try starting the subset at each index
        for (int i = 0; i < n; i++) {
            int size = lds(arr, memo, parent, i);
            if (size > maxSize) {
                maxSize = size;
                lastIndex = i;
            }
        }

        // Backtrack to construct the subset
        vector<int> res;
        for (int i = lastIndex; i >= 0; i = parent[i]) {
            res.push_back(arr[i]);
            if (parent[i] == -1)
                break;
        }

        // The result is already in descending order, no need to reverse
        return res;
    }
};
