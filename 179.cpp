//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
         int n=arr.size();
         if(n<2) return {};
        int l=0;
        int r=n-1;
        int a,b; // for storing the indices of pair
        int diff=INT_MAX;  // diffrence between sum of element & given k
        while(l<r){
            int sum=arr[l]+arr[r];
            if(abs(sum-k)<diff){
                a=l;
                b=r;
                diff=abs(sum-k);  // update diff on getting new minimal difference pair
            }
            if(sum>k){   // if pair sum is greater  move towards left
                r--;
            }
            else{    // if pair sum is small move toward right 
                l++;
            }
        }
        return {arr[a],arr[b]};
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
