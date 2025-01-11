//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int l = 0, r = 0, n = s.size();
        vector<int> hash(26, -1);
        int maxLen = 1;
        while( r < n ) {
            if(hash[s[r] - 'a'] != -1 && 
            l <= hash[s[r] - 'a']) {
                l = hash[s[r] - 'a'] + 1;
            }
            maxLen = max(maxLen, r - l + 1);
            hash[s[r] - 'a'] = r;
            r++;
        }
        return maxLen;
    }
};






//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
