//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int solve(vector<int>&prices,bool buy,int index,int &n, int limit,vector<vector<vector<int>>>&dp)
    {
        if(index==n)
        return 0;
        
        if(limit==0)
        return 0;
        
        
        if(dp[index][buy][limit]!=-1)
        return dp[index][buy][limit];
        
        int include=0;
        int exclude=0;
        if(buy)
        {
            include=-prices[index]+solve(prices,false,index+1,n,limit,dp);
            exclude=solve(prices,buy,index+1,n,limit,dp);
        }
        else
        {
           
            
            include=prices[index]+solve(prices,true,index+1,n,limit-1,dp);
            exclude=solve(prices,buy,index+1,n,limit,dp);
            
        }
        
        return dp[index][buy][limit]=max(include,exclude);
        
        
    }
    int maxProfit(vector<int>& prices, int k) {
        
        bool buy=true;
        int index=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        int limit=k;
        int ans=solve(prices,buy,index,n,limit,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
