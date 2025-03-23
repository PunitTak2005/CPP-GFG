//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  unordered_map<string, int> dp;
  int solve(vector<int>&arr, int i, int j){
      if(i>=j){
          return 0;
      }
      int mini = INT_MAX;
      string memo = to_string(i)+","+to_string(j);
      if(dp.count(memo)){
          return dp[memo];
      }
      
      for(int k = i; k<j; k++){
          int ans1 = solve(arr, i, k);
          int ans2 = solve(arr, k+1, j);
          
          int cost = arr[i-1]*arr[k]*arr[j];
          
          mini = min(mini, ans1+ans2+cost);
      }
      return dp[memo]=mini;
  }
    int matrixMultiplication(vector<int> &arr) {
        return solve(arr, 1, arr.size()-1);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
