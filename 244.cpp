//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(int i,int j,string& s1, string& s2,vector<vector<int>> &dp){
        if(i >= s1.length())
            return s2.length()-j;
        if(j >= s2.length())
            return s1.length()-i;
        
        if(dp[i][j] != -1)
           return dp[i][j];
           
        int matched = INT_MAX,unMatched = INT_MAX;
        if(s1[i] == s2[j])
            matched = solve(i+1,j+1,s1,s2,dp);
        else{
            int insert = 1 + solve(i,j+1,s1,s2,dp);
            int deletee = 1 + solve(i+1,j,s1,s2,dp);
            int replace = 1 + solve(i+1,j+1,s1,s2,dp);
            unMatched = min(insert,min(deletee,replace));
        }
        return dp[i][j] = min(matched,unMatched);
    }
    int editDistance(string& s1, string& s2) {
        int n1 = s1.length(),n2 = s2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        
        int ans = solve(0,0,s1,s2,dp);
        return ans == INT_MAX ? 0 : ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
