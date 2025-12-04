class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        long long ops = 0;

        for (int x : nums) {
            if (x == 0) continue;          // already zero

            // End all layers that are too high to pass through x
            while (!st.empty() && st.back() > x) {
                st.pop_back();
            }

            // If no active layer or top < x, start a new layer
            if (st.empty() || st.back() < x) {
                st.push_back(x);
                ++ops;
            }
            // else top == x: extend existing layer; no new op
        }
        return (int)ops;
    }
};
