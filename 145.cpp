#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // Sort in descending order
        int h_index = 0;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                h_index = i + 1;
            } else {
                break;
            }
        }
        return h_index;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> citations(n);
        for (int i = 0; i < n; ++i) {
            cin >> citations[i];
        }

        Solution ob;
        int result = ob.hIndex(citations);
        cout << result << endl;
        cout << "~" << endl; // Added separator for clarity
    }
    return 0;
}
