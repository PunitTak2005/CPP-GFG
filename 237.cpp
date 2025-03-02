//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
    int left = 0, right = 0;
    int maxLen = 0, startIndex = 0;
    int minVal = arr[0], maxVal = arr[0];

    while (right < n) {
        minVal = min(minVal, arr[right]);
        maxVal = max(maxVal, arr[right]);

        while (maxVal - minVal > x) {
            left++;
            minVal = *min_element(arr.begin() + left, arr.begin() + right + 1);
            maxVal = *max_element(arr.begin() + left, arr.begin() + right + 1);
        }

        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            startIndex = left;
        }
        right++;
    }

    return vector<int>(arr.begin() + startIndex, arr.begin() + startIndex + maxLen);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
