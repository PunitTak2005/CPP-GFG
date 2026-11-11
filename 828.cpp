class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];

            if (lastIndex.find(x) != lastIndex.end() &&
                i - lastIndex[x] <= k) {
                return true;
            }

            lastIndex[x] = i;
        }

        return false;
    }
};
