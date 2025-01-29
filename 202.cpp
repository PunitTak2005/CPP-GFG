//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int c(int i,int j,vector<vector<int>>&a,int n){
        int k=j,k1=j;
        while(i>=0){
            if(k1>=0 && k1<n){
                if(a[i][k1]==1){return 0;}}
            if(k>=0 && k<n){
                if(a[i][k]==1){return 0;}}
            if(j>=0 && j<n){
                if(a[i][j]==1){return 0;}}
            k1--; k++; i--;}
        return 1;}
        
    void solve(int i,int n,vector<vector<int>>&a,vector<vector<int>>&ans,vector<int>p){
        if(i>=n){
            if(p.size()!=n){return;}
            ans.push_back(p); return;}
        for(int j=0;j<n;j++){
            if(c(i,j,a,n)==1){
                p.push_back(j+1);
                a[i][j]=1;
                solve(i+1,n,a,ans,p);
                p.pop_back();
                a[i][j]=0;  }  }
        return;
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans,a(n,vector<int>(n,0));
        vector<int>p;
        solve(0,n,a,ans,p);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
