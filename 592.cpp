class Solution {
public:
    long long trappingWater(vector<int>& arr, int n) {
        int l = 0, r = n - 1;
        long long lMax = 0, rMax = 0, ans = 0;

        while (l <= r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] >= lMax) {
                    lMax = arr[l];
                } else {
                    ans += (lMax - arr[l]);
                }
                l++;
            } else {
                if (arr[r] >= rMax) {
                    rMax = arr[r];
                } else {
                    ans += (rMax - arr[r]);
                }
                r--;
            }
        }
        return ans;
    }

    long long maxWater(vector<int>& arr) {   // called by Driver.cpp
        int n = arr.size();
        return trappingWater(arr, n);
    }
};
