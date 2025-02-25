
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     vector<int> next(vector<int>& heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            int num = heights[i];
            while(s.top()!=-1 && heights[s.top()] >= num){
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prev(vector<int>& heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int num = heights[i];
            while(s.top()!=-1 && heights[s.top()] >= num){
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;
    }
    int getMaxArea(vector<int> &heights) {
        // Your code here
        int n = heights.size();
        vector<int> nxt(n);
        nxt = next(heights,n);
        vector<int> prv(n);
        prv = prev(heights,n);
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            if(nxt[i]==-1){
                nxt[i]=n;
            }
            int w = nxt[i]-prv[i]-1;
            int area = w*heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
