class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int res = 0;

        // pointers to mark the left and right boundary
        int left = 0, right = 0;

        // frequency map
        unordered_map<int, int> freq;
        while (right < n) {
            freq[arr[right]] += 1;

            // if this is a new element in the window,
            // decrement k by 1
            if (freq[arr[right]] == 1)
                k -= 1;

            // shrink the window until distinct element
            // count becomes <= k
            while (k < 0) {
                freq[arr[left]] -= 1;
                if (freq[arr[left]] == 0)
                    k += 1;
                left += 1;
            }

            // count of subarrays ending at "right"
            // and having atmost k elements
            res += (right - left + 1);
            right += 1;
        }
        return res;
    }
};
