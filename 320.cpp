//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int countSubstring(string &s) {
        int n = s.length();

        // Create an array to store
        // frequency of characters
        vector<int> freq(26, 0);

        // Update frequency of each character
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int count = 0;

        // For each character, calculate number of substrings
        // that start and end with that character
        for (int i = 0; i < 26; i++) {

            // Number of substrings with same
            // first and last character is
            // nC2 + n = n*(n+1)/2
            count += (freq[i] * (freq[i] + 1)) / 2;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
