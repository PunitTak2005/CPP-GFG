class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(arr.size(), false);
        
        // Sort for lexicographic order
        sort(arr.begin(), arr.end());
        
        backtrack(arr, used, curr, ans);
        return ans;
    }
    
private:
    void backtrack(vector<int>& arr, vector<bool>& used, 
                   vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == arr.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;
            
            // Skip duplicates
            if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;
            
            curr.push_back(arr[i]);
            used[i] = true;
            
            backtrack(arr, used, curr, ans);
            
            curr.pop_back();
            used[i] = false;
        }
    }
};
