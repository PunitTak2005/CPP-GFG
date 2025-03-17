//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  bool solve(vector<int>arr,int i,int sum,int tsum , vector<vector<int>>&dp){
        if(i>arr.size()) return false;
         if(tsum==sum) return true;
         if(dp[i][sum]!= -1) return dp[i][sum]; 
        bool a  = solve(arr,i+1,sum+arr[i],tsum,dp);
        bool b = solve(arr,i+1,sum,tsum,dp);
        return dp[i][sum] = a||b; 
        
    }
  
    bool equalPartition(vector<int>& arr) {
        
        
        unordered_map<int,int>map; 
        int tsum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>>dp(arr.size()+1,vector<int>(tsum+1,-1)); 
        if(tsum%2!= 0) return false; 
        return solve(arr,0,0,tsum/2,dp); 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
