class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1);

        // Left to right
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        long long sum = 0;
        for (int c : candies) sum += c;
        return (int)sum;
    }
};
