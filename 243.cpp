//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans = 0 ; 
        int n = s.size(); 
        for(int i = 0 ; i < n; i++){
            int start = i-1 ; 
            int end = i+1 ; 
            while(start >= 0 && end < n && s[start] == s[end] ){
                start--;
                end++;
                ans++;
            }
            start = i ; 
            end = i+1; 
            while(start >= 0 && end < n && s[start] == s[end] ){
                start--;
                end++;
                ans++;
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
