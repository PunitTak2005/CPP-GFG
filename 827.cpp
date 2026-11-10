class Solution {
public:
    int firstElementKTime(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
            if (freq[x] == k) {
                return x;
            }
        }

        return -1;
    }
};
