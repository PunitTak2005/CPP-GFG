class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n + 1, 0);
        stack<int> s;

        // find window sizes for each element
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                int top = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                int window_size = right - left - 1;
                len[window_size] = max(len[window_size], arr[top]);
            }
            s.push(i);
        }

        // process remaining elements in stack
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int left = s.empty() ? -1 : s.top();
            int right = n;
            int window_size = right - left - 1;
            len[window_size] = max(len[window_size], arr[top]);
        }

        for (int i = 1; i <= n; i++) {
            res[i - 1] = len[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        return res;
    }
};
