class Solution {
public:
    int kBitFlips(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0); // track flips at each index
        int flip = 0; // current flip state
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flip ^= isFlipped[i - k]; // remove effect of old flips
            }

            if ((arr[i] ^ flip) == 0) { // agar current bit after flip = 0 hai
                if (i + k > n) return -1; // agar window bahar ja rahi hai
                res++;
                flip ^= 1; // flip karna hoga
                isFlipped[i] = 1; // mark flip at this index
            }
        }
        return res;
    }
};
