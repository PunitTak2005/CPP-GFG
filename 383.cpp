class Solution {
  public:

    // Function to compute the prime
    // factorization of a number 'num'
    vector<vector<int>> primeFactors(int num) {
        vector<vector<int>> factors;

        int count = 0;
        while (num % 2 == 0) {
            num /= 2;
            count++;
        }
        if (count > 0)
            factors.push_back({2, count});

        // Check for odd factors starting from 3
        for (int i = 3; i * i <= num; i += 2) {
            count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            if (count > 0)
                factors.push_back({i, count});
        }

        // If 'num' is still greater than 1,
        // it's a prime number
        if (num > 1)
            factors.push_back({num, 1});

        return factors;
    }

    // Function to compute how many times prime p
    // appears in n! using Legendre's formula
    int legendre(int n, int p) {
        int count = 0;
        for (int power = p; power <= n; power *= p) {
            count += n / power;
        }
        return count;
    }

    // Function to find the largest power of k that divides n!
    int maxKPower(int n, int k) {

        vector<vector<int>> factors = primeFactors(k);

        int result = INT_MAX;

        for (auto &factor : factors) {
            int prime = factor[0];
            int expInK = factor[1];

            // Count total exponent of 'prime' in n!
            // using Legendre’s formula
            int countInFact = legendre(n, prime);

            // Divide by its exponent in k
            result = min(result, countInFact / expInK);
        }

        return result;
    }
};
