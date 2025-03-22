//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int solve(vector<int>& arr){
        int n = arr.size();
        
        vector<int> dp(n+2 , 0);
        
        for(int i = n-1 ; i>=0 ; i--){
            int inc = arr[i] + dp[i+2];
            int exc = dp[i+1];
            
            dp[i] = max(inc , exc);
        }
        return dp[0];
    }
    int maxValue(vector<int>& arr) {
        
        vector<int> a(arr.begin()+1 , arr.end()) , b(arr.begin() , arr.end()-1);
        
        return max(solve(a) , solve(b));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
