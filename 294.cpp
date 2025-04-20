//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int ogsum = 0;
        for(int i = 1; i < n ; i++) ogsum += i;
        int actual_sum = 0;
        for(int i = 0 ; i < n ; i++) actual_sum += arr[i];
        return actual_sum - ogsum;
        
        // long long actual_sum = (n*(n+1))/2;
        // long long actual_sq_sum = (n * (n+1) * (2*n+1))/6;
        // long long given_sum = 0, given_sq_sum = 0;
        // for(int i : arr) {
        //     given_sum += i;
        //     given_sq_sum += i * i;
        // }
        // return abs(actual_sum-given_sum);
        // long long a_minus_b = given_sum - actual_sum;
        // long long asq_minus_bsq = given_sq_sum - actual_sq_sum;
        // long long a_plus_b = (asq_minus_bsq) / a_minus_b;
        // long long a = (a_plus_b + a_minus_b) / 2;
        // long long b = (a_plus_b - a_minus_b) / 2;
        // // cout<<a<<" "<<b<<endl;
        // return a;
    }
};




//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
