//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int minCoins(vector<int> &coins, int V) {
        int M = coins.size();
        vector<int>next(V+1);
        vector<int>curr(V+1);
    
        for(int i=0;i<=V;i++)
            next[i] = (i%coins[M-1]==0)?i/coins[M-1]:INT_MAX;
        
        for(int i=M-2;i>=0;i--){
            for(int j=0;j<=V;j++){
                int take=INT_MAX;
                int dtake = next[j];
                if(j>=coins[i]){
                    int res = curr[j-coins[i]];
                    if(res!=INT_MAX)
                        take=1 + res;
                }
                curr[j] = min(take,dtake);
            }
            next=curr;
        }
        return next[V]==INT_MAX?-1:next[V];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
