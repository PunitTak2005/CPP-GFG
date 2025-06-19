class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first; // smallest available number
            for (int i = 0; i < k; i++) {
                int current = start + i;
                if (freq[current] == 0) {
                    return false; // missing number in sequence
                }
                freq[current]--;
                if (freq[current] == 0) {
                    freq.erase(current); // remove if used up
                }
            }
        }

        return true;
    }
};
