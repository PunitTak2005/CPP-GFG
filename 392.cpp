


class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // Step 1: Create sets for allowed and not-allowed digits
        unordered_set<int> allowed(arr.begin(), arr.end());

        // Step 2: If all digits are allowed, return total n-digit numbers
        if (allowed.size() == 10) {
            return 9 * pow(10, n - 1);
        }

        // Step 3: Count how many digits are NOT allowed
        vector<int> notAllowed;
        for (int d = 0; d <= 9; d++) {
            if (allowed.find(d) == allowed.end()) {
                notAllowed.push_back(d);
            }
        }

        // Step 4: Count total n-digit numbers that use only not-allowed digits
        int invalid = 0;
        int k = notAllowed.size();

        if (k == 0) return 0; // nothing to exclude

        // First digit can't be zero
        int firstDigitChoices = 0;
        for (int d : notAllowed) {
            if (d != 0) firstDigitChoices++;
        }

        if (firstDigitChoices > 0) {
            invalid = firstDigitChoices * pow(k, n - 1);
        } else {
            invalid = 0;
        }

        // Total n-digit numbers = 9 * 10^(n-1)
        int total = 9 * pow(10, n - 1);

        // Final valid count
        return total - invalid;
    }
};
