//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if((i+1)<n && arr[i]==arr[i+1])
            {
                i++;
            }
            else
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
