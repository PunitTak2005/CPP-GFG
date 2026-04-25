class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st; // acts as a stack

        for (int x : arr) {
            bool destroyed = false;

            // while there is a possible opposite-sign pair with current x
            while (!st.empty() && st.back() * x < 0) {
                int y = st.back();

                if (abs(y) < abs(x)) {
                    // current x has greater abs value, y removed
                    st.pop_back();
                    // continue to check with new top
                } else if (abs(y) == abs(x)) {
                    // both removed
                    st.pop_back();
                    destroyed = true;  // x also removed
                    break;
                } else { 
                    // abs(y) > abs(x): x removed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(x);
            }
        }

        return st;
    }
};
