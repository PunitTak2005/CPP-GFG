//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int recur(vector<int> &coins, int i, int sum, vector<vector<int>> &dp) {
    if (sum == 0) return 1; // Found a valid combination
    if (i == coins.size() ) return 0; // No valid combination possible
    if(dp[i][sum]!=-1) return dp[i][sum];
    // Take the coin and remain at the same index
    int take = 0;
    if (sum - coins[i] >= 0) {
        take = recur(coins, i, sum - coins[i], dp);
    }

    // Don't take the coin and move to the next index
    int nt = recur(coins, i + 1, sum, dp);

    // Total number of combinations = take + nt
    return dp[i][sum]=take + nt;
}

int count(vector<int>& coins, int sum) {
    vector<vector<int>> dp(coins.size(),vector<int> (sum+1,-1));
    sort(coins.begin(), coins.end()); 
    return recur(coins, 0, sum, dp);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
