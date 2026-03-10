class Solution {
public:
    long long countSubarrays(vector<int> &arr) {
        int n = arr.size();
        vector<int> nxt(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) nxt[i] = n;
            else nxt[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)(nxt[i] - i);
        }
        return ans;
    }
};
