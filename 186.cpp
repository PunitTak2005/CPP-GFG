//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        if(arr.size()==1) return 0;
        
        int MaxWater=0,i=0,j=arr.size()-1;
        
        while(i<j){
            
            int distance=j-i;
            
            MaxWater=max(min(arr[i],arr[j])*distance,MaxWater);
            
            if(arr[i]<arr[j]) i++;
            
            else j--;
        }
      
        return MaxWater;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends