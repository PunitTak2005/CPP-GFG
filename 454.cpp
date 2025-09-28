class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        multiset<int> window;
        int start = 0, maxLen = 0, left = 0;

        for (int right = 0; right < n; right++) {
            window.insert(arr[right]);

            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                left++;
            }

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
        }

        vector<int> res;
        for (int i = start; i < start + maxLen; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
