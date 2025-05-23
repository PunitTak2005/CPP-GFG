
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        
         unordered_map<int,int>mp;
            
              int n=arr.size();
              int c=0;
              int sum=0;
              for (int i:arr){
                  sum+=i;
                  
                  if (sum==k) c++;
                  if (mp.find(sum-k)!=mp.end()){
                      c+=mp[sum-k];
                  }
                  mp[sum]++;
              }
              return c;
    }
};


int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
