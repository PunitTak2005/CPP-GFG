//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


  
class Solution {
    int mod  = 1e9+7;
  public:
    int countWays(string &str) {
      
            if(str.empty() || str[0] ==  '0') return 1;
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
 
    for(int i=2; i<=n; i++){
        int one = str[i-1]-'0';                                                  
        int two = stoi(str.substr(i-2, 2));
        if(one != 0){
            dp[i] += dp[i-1]%mod;
        }
        if(two >= 10 && two <= 26){
            dp[i] += dp[i-2]%mod;
        }
    }
    return dp[n]%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
