class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Find the maximum frequency
        int maxFreq = 0;
        for (pair<int, int> entry : freq) {
            maxFreq = max(maxFreq, entry.second);
        }

        // Create buckets based on frequencies
        // Each bucket index represents frequency
        vector<vector<int>> buckets(maxFreq + 1);
        for (pair<int, int> entry : freq) {
            buckets[entry.second].push_back(entry.first);
        }

        // Collect top k frequent elements
        vector<int> res;
        for (int i = maxFreq; i >= 1; --i) {

            sort(buckets[i].begin(), buckets[i].end(), greater<int>());

            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
