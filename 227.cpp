//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isBalanced(string& x) {
        // code here
        stack<char> st;
        st.push('A');
        // if(x.size()==1 || x.size()==0) return false;
        for(int i=0;i<x.size();i++) {
            char c = x[i];
            if(c == '[' || c == '{' || c == '(') 
                st.push(x[i]);
            else if(c == ')' && st.top() == '(')
                st.pop();
            else if(c == ']' && st.top() == '[')
                st.pop();
            else if(c == '}' && st.top() == '{')
                st.pop();
            else return false;
        }
        if(st.size()!=1) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
