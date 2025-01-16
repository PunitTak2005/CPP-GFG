//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int,int> prifixSum;
        int n=arr.size(), sum=0, ans=0;
        for(int i=0; i<n; i++){
            sum += (arr[i]==1?1:-1);
            if(sum==0){
                ans=i+1;
            }
            if(prifixSum.find(sum)!=prifixSum.end()){
                ans=max(ans,i-prifixSum[sum]);
            }
            else{
                prifixSum[sum]=i;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends
