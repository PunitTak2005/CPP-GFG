class Solution {
public:
    int findKthSmall(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int i = 0;
        int n = arr.size();

        while (i < n && arr[i] <= k + i) {
            i++;
        }

        return k + i;
    }
};
