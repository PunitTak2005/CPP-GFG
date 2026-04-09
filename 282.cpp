class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            // Skip duplicates in a
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            
            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        // Remove possible duplicates added due to duplicates in b
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
