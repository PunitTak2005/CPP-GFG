//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int ans = arr[0];
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(count == 0){
                ans = arr[i];
            }
            if(arr[i] == ans){
                count++;
            }
            else if(arr[i] != ans){
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == ans) {
                count++;
            }
        }
    
        if(count > arr.size() / 2)
            return ans;
        else
            return -1;
        }
};





//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
