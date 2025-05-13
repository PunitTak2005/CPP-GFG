//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n)
            return 0;

        long long sum = 1;

        // Calculate the value using
        // the binomial coefficient formula
        for (int i = 1; i <= r; i++) {
            sum = sum * (n - r + i) / i;
        }
        return (int)sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
