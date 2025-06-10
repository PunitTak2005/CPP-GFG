class Solution {
  public:
    // Function to find the length of the stack after performing operations.
    int findLength(vector<int> color, vector<int> radius) {
        int n = color.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {

            // If the top of the stack matches
            // current, pop it (remove both)
            if (!st.empty() && color[i] == color[st.top()] &&
                radius[i] == radius[st.top()]) {
                st.pop();
            }

            else {
                st.push(i);
            }
        }

        // Return the number of elements
        // left in the stack
        return st.size();
    }
};
