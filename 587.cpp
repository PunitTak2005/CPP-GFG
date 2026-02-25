class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            if (ca == cb) return a < b;   // when same 1-bits, sort by value
            return ca < cb;               // otherwise sort by bit-count
        });
        return arr;
    }
};
