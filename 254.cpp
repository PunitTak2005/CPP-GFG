//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        vector<int> v1(prices.size());
        vector<int> v2(prices.size());
        v1[0]=0;
        int minm=prices[0];
        for(int i=1;i<prices.size();i++){
            minm=min(minm,prices[i]);
            v1[i]=max(v1[i-1],(prices[i]-minm));
        }
        int maxm=prices[prices.size()-1];
        v2[prices.size()-1]=0;
        for(int i=prices.size()-2;i>=0;i--){
            maxm=max(maxm,prices[i]);
          v2[i]=max(v2[i+1],(maxm-prices[i]));
        }
        
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans=max(ans,v1[i]+v2[i]);
        }
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
