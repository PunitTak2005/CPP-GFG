class Solution {
public:
    int maxSubstring(string &s) {
        int max_ending_here = 0;
        int max_so_far = INT_MIN;

        for (char c : s) {
            int val = (c == '0') ? 1 : -1; // +1 for '0', -1 for '1'
            max_ending_here = max(val, max_ending_here + val);
            max_so_far = max(max_so_far, max_ending_here);
        }

        // If all are '1', max_so_far will be <= 0
        if (max_so_far <= 0) return -1;
        return max_so_far;
    }
};
