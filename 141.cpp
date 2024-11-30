//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to check whether two strings are anagrams of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // If the lengths of the strings are different, they cannot be anagrams.
        if (s1.size() != s2.size()) {
            return false;
        }

        // Create frequency maps for both strings.
        unordered_map<char, int> freq1, freq2;
        for (char c : s1) {
            freq1[c]++;
        }
        for (char c : s2) {
            freq2[c]++;
        }

        // Compare frequency maps.
        return freq1 == freq2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string c, d;
        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
}
// } Driver Code Ends
