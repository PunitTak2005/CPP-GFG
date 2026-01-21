class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // stores indices

        for (int i = 0; i < n; ++i) {
            // Pop all elements with price <= current price
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                // No greater element to the left
                span[i] = i + 1;
            } else {
                // Nearest greater element on left is at st.top()
                span[i] = i - st.top();
            }

            st.push(i);
        }
        return span;
    }
};
