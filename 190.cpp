//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> pref(n),suf(n);
        pref[0]=arr[0];
        suf[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]*arr[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]*arr[i];
        }
        vector<int> ans;
        ans.push_back(suf[1]);
        for(int i=1;i<n-1;i++)
        {
            ans.push_back(pref[i-1]*suf[i+1]);
        }
        ans.push_back(pref[n-2]);
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
