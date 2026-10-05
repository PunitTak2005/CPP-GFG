class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();

                int value = (innerScore == 0) ? 1 : 2 * innerScore;

                st.top() += value;
            }
        }

        return st.top();
    }
};
