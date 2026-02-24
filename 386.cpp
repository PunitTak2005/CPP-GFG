class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int,int> firstPos; // prefixSum -> first index
        int prefix = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = a1[i] - a2[i];
            prefix += diff;
            
            if (prefix == 0) {
                // subarray [0..i] has sum 0
                ans = max(ans, i + 1);
            }
            
            if (firstPos.find(prefix) != firstPos.end()) {
                // longest subarray ending at i with same prefix
                ans = max(ans, i - firstPos[prefix]);
            } else {
                // store first occurrence of this prefix sum
                firstPos[prefix] = i;
            }
        }
        
        return ans;
    }
};
