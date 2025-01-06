//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int s=0;
        int e=arr.size()-1;
        int ans=0;
        while(s<e){
            int sum=arr[s]+arr[e];
            if(sum<target){
                s++;
            }
            else if(sum==target){
                int t1=arr[s];
                  int t2=arr[e];
                  int c1=0,c2=0;
                  while(s<=e&&arr[s]==t1){
                      s++;
                      c1++;
                  }
                  while(s<=e&&arr[e]==t2){
                      e--;
                      c2++;
                  }
                  ans+=(t1==t2)?(c1*(c1-1))/2:c1*c2;
            }
            else{
                e--;
            }
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
