//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int missingCount = 0;
        int current = 1; // Start checking from 1
        
        // Traverse the array to count missing numbers
        for (int i = 0; i < n; i++) {
            // Count how many numbers are missing before arr[i]
            while (current < arr[i]) {
                missingCount++;
                if (missingCount == k) {
                    return current;
                }
                current++;
            }
            current = arr[i] + 1; // After arr[i], the next number is arr[i] + 1
        }
        
        // If the kth missing number is beyond the last element in arr
        while (missingCount < k) {
            missingCount++;
            current++;
            if (missingCount == k) {
                return current - 1;
            }
        }
        
        return -1; // This should never be reached
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
