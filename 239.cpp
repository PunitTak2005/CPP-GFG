//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n;
    // bool valid(string s1, string s2){
    //     if(s1.size()+1==s2.size()){
    //         int c=0;
    //         int n=s1.size();
    //         int i=0;
    //         int j=0;
    //         while(i<n && j<n+1){
    //             if(s1[i]!=s2[j]){
    //                 c++;
    //                 j++;
    //             }
    //             i++;
    //             j++;
    //         }
    //         if(c>1)return false;
    //         // while(j<n+1)c++;
    //         return true;
    //     }
    //     return false;
    // }
    // int fun(int st, int j, int k, vector<vector<int>> &dp, vector<string> &words){
    //     if(j>=n)return k;
    //     // if(dp[])
    //     if(words[st].size()>=words[j].size()){
    //         return fun(st,j+1,k,dp,words);
    //     }else if(valid(words[st],words[j])){
    //         return max(fun(j,j+1,k+1,dp,words), fun(st,j+1,k,dp,words));
    //     }else{
    //         return fun(st,j+1,k,dp,words);
    //     }
    // }
    static bool comp(string &a, string &b){
        return a.size()<=b.size();
    }
    
    int longestStringChain(vector<string>& words) {
        
        // int ans = 0;
        // unordered_map<string, int> dp;

        // // Sort words based on their length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

       
        n=words.size();
        // sort(words.begin(),words.end(), comp);
        
        unordered_map<string,int> dp;
        int res=0;
        for(auto word:words){
            dp[word]=1;
            for(int i=0;i<word.size();i++){
                string pred = word.substr(0,i) + word.substr(i+1);
                if(dp.find(pred)!=dp.end()){
                    dp[word]=max(dp[word],dp[pred]+1);
                }
            }
            res=max(res,dp[word]);
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
