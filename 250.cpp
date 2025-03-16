//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int f(int ind,vector<int>& arr,vector<int>&dp){
      if(ind==arr.size()-1){
          return 0;
      }
      if(dp[ind]!=-1){
          return dp[ind];
      }
      int ans=INT_MAX;
      for(int i=ind+1;i<=min(ind+arr[ind], int(arr.size()-1));i++){
          int c=f(i,arr,dp);
          
          if(c!=INT_MAX){
              ans=min(ans,1+c);
          }
          
      }
      return dp[ind]=ans;
  }
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans=f(0,arr,dp);
        return ans==INT_MAX?-1:ans;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
