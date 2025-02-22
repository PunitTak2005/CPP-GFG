//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int open=0;
        int close=0;
        int maxlen=0;
        for(auto ch:s)
        {
            if(ch=='(')
            open++;
            else
            close++;
            if(open==close)
            maxlen=max(maxlen,2*close);
            else if(close>open)
            open=close=0;
        }
            open=close=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
            close++;
            else
            open++;
            if(open==close)
            maxlen=max(maxlen,2*open);
            else if(open>close)
            open=close=0;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
