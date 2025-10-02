
class Solution {
  public:
    void findCombinations(int n, int k, vector<int>& subVector,
                          vector<vector<int>>& res, int last) {
        if (n == 0 && k == 0) {
            res.push_back(subVector);
            return;
        }
        if (n < 0 || k < 0) return;

        for (int i = last; i <= 9; i++) {
            subVector.push_back(i);
            findCombinations(n - i, k - 1, subVector, res, i + 1);
            subVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        if (n < k || n > 9 * k) return {};
        
        vector<vector<int>> res;
        vector<int> subVector;
        findCombinations(n, k, subVector, res, 1);
        return res;
    }
};
