class Solution {
  public:
    void solve(int n, int current_digit, int current_num, vector<int>& ans) {
        // Base case: When we have added N digits, store the number
        if (n == 0) {
            ans.push_back(current_num);
            return;
        }

        // Next digit must be strictly greater than current_digit
        for (int i = current_digit + 1; i <= 9; i++) {
            // Build the number mathematically, avoiding strings entirely
            solve(n - 1, i, current_num * 10 + i, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        // Edge case: n = 1 is the only time 0 is included
        if (n == 1) {
            for (int i = 0; i <= 9; i++) {
                ans.push_back(i);
            }
            return ans;
        } else if (n > 9)
            return ans;

        // For n > 1, the first digit must be between 1 and 9
        for (int i = 1; i <= 9; i++) {
            solve(n - 1, i, i, ans);
        }

        return ans;
    }
};
