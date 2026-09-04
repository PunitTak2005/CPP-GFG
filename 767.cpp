class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        m = min(m, n);

        long long sum = 0, ans = 0;

        // First window
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        ans = sum;

        // Slide across remaining circular windows
        for (int start = 1; start < n; start++) {
            sum -= arr[start - 1];
            sum += arr[(start + m - 1) % n];
            ans = max(ans, sum);
        }

        return ans;
    }
};
