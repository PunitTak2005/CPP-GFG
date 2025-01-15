//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxWater(vector<int> &arr) {
    
        
        int n = arr.size();
        int lmax=INT_MIN;
      int rmax=INT_MIN;
      int i=0;
      int j=n-1;
      long long sum=0;
      while(i<j){
          if(arr[i]>lmax){
              lmax=arr[i];
          }
          if(arr[j]>rmax){
              rmax=arr[j];
          }
          if(lmax<rmax){
              sum+=lmax-arr[i++];
          }else{
              sum+=rmax-arr[j--];
          }
          
          
      }
      return sum;
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