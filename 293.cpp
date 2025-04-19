//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    struct TrieNode {
        TrieNode* children[2] = {nullptr, nullptr};
    };
    
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXor(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggleBit = 1 - bit;
            if (node->children[toggleBit]) {
                maxXor |= (1 << i);
                node = node->children[toggleBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
    
    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        int maxResult = 0;
        
        // Insert first number to avoid comparing it with itself
        insert(root, arr[0]);
        
        for (int i = 1; i < arr.size(); i++) {
            maxResult = max(maxResult, findMaxXor(root, arr[i]));
            insert(root, arr[i]);
        }
        
        return maxResult;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
