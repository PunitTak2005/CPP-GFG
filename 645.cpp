class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> st; // acts as stack

        for (int x : arr) {
            if (!st.empty()) {
                int y = st.back();
                bool oppSign = (y < 0 && x >= 0) || (y >= 0 && x < 0);
                if (oppSign) {
                    st.pop_back(); // remove conflicting pair
                    continue;
                }
            }
            st.push_back(x);
        }

        // st already has elements in correct left-to-right order
        return st;
    }
};
