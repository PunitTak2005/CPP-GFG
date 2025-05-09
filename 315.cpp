//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> prefixMap;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Convert the element to +1 or -1
            int val = (arr[i] > k) ? 1 : -1;
            prefixSum += val;

            // If sum is positive from the beginning
            if (prefixSum > 0) {
                maxLength = i + 1;
            }

            // If prefixSum is seen before, check max length
            if (prefixMap.find(prefixSum - 1) != prefixMap.end()) {
                maxLength = max(maxLength, i - prefixMap[prefixSum - 1]);
            }

            // Store the first occurrence of the prefixSum
            if (prefixMap.find(prefixSum) == prefixMap.end()) {
                prefixMap[prefixSum] = i;
            }
        }

        return maxLength;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
