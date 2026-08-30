class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> pref(n);
        
        for (int i = 0; i < n; i++) {
            long long len = 1LL * r[i] - l[i] + 1;
            pref[i] = len + (i ? pref[i - 1] : 0);
        }
        
        vector<int> ans;
        
        for (int k : rank) {
            int idx = lower_bound(pref.begin(), pref.end(), (long long)k) - pref.begin();
            
            long long before = (idx == 0 ? 0 : pref[idx - 1]);
            ans.push_back(l[idx] + (k - before - 1));
        }
        
        return ans;
    }
};
