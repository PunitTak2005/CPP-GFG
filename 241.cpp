//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
  
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
       if(i>j){
           return 0;
           
       }
       if(i==j){
           return 1;
       }
       
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       
       if(s[i]==s[j]){
           return dp[i][j]= 2+solve(i+1,j-1,s,dp);
       }else{ 
           dp[i][j] = max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
       }
       
       return dp[i][j];
    }
    int longestPalinSubseq(string &s) {
       int n = s.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,dp);
    }
};




//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
