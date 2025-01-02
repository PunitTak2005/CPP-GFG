
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
         map<int,int>mp;
         int n=arr.size();
         int currxor=0;
         int ans=0;
         mp[0]++;
         for(int i=0;i<n;i++){
             currxor^=arr[i];
             if(mp.find(currxor^k)!=mp.end())
             ans+=mp[currxor^k];
             mp[currxor]++;
         }
         return ans;
    }
};



int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
