class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        
        // length of sequential-number window
        for (int len = 2; len <= 9; ++len) {
            // start index of window in "123456789"
            for (int start = 0; start + len <= 9; ++start) {
                string sub = s.substr(start, len);
                int val = stoi(sub);
                
                if (val >= low && val <= high) {
                    ans.push_back(val);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
