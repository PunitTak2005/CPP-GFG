class Solution {
public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: single element
        if (n == 1) {
            return arr[0];
        }

        long long int prod = 1;
        int max_neg = INT_MIN;
        int count_neg = 0;
        int count_zero = 0;
        int count_pos = 0;
        long long int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            // If the element is 0, skip it for the product product calculation
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }

            // Track negative elements
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            } else {
                count_pos++;
            }

            // Keep taking product modulo 10^9 + 7
            prod = (prod * abs(arr[i])) % MOD;
        }

        // If all elements were zeros
        if (count_zero == n) {
            return 0;
        }

        // If there are only negative numbers and zeros, and only 1 negative number
        if (count_neg == 1 && count_pos == 0 && count_zero > 0) {
            return 0;
        }

        // If odd number of negatives, remove the largest negative value
        if (count_neg % 2 != 0) {
            // Using modular inverse to safely "divide" out the max_neg absolute value
            // Or alternatively, re-compute the product omitting it.
            // Since we need to return modulo 10^9+7, let's just do a clean calculation pass or use modular division:
            prod = 1;
            bool skipped = false;
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) continue;
                if (arr[i] == max_neg && !skipped) {
                    skipped = true; // skip exactly one instance of the largest negative
                    continue;
                }
                prod = (prod * arr[i]) % MOD;
            }
            // Ensure product is positive if it became negative through standard multiplication
            if (prod < 0) prod = (prod + MOD) % MOD;
            return prod;
        }

        // Re-verify the sign if we multiplied elements directly
        // Because our initial loop took abs(arr[i]), the product represents the correct magnitude.
        // Since count_neg is even, the actual product of non-zero elements is guaranteed to be positive.
        return prod;
    }
};
