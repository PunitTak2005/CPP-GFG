class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        long long currMax = arr[0];
        long long currMin = arr[0];
        long long ans = arr[0];

        for (int i = 1; i < n; i++) {
            long long x = arr[i];

            if (x < 0) {
                swap(currMax, currMin);
            }

            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);

            ans = max(ans, currMax);
        }

        return (int)ans;
    }
};
