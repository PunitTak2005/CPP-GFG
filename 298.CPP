//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int n = arr.size();
        
        //creatin a map 
        unordered_map<int,int>freq;
        //traversing thea array to store the freq of each ele
        for(int i =0;i<n;i++){
            freq[arr[i]]++;
        }
    
        //Now traversing the map 
        for(auto it: freq){
            if(it.second==1){
                return it.first;
            }
        }
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
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
