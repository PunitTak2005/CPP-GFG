//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& str) {
      
        set<char> set;
        for(auto &c:str){
            set.insert(c);
        }
        int n = set.size();
        
        unordered_map<int,int> mp;
        int l=0,r=0; int ans = str.length();
        while(r<str.length()){
            mp[str[r]]++;
            if(mp.size()==n){
                while(mp[str[l]]>1){
                    mp[str[l]]--;
                    l++;
                }
                ans = min(ans,r-l+1);
            }
            r++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
