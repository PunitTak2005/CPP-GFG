class Solution {
public:
   string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ans;
       for(auto & s : words){
           int total = 0;
           for(auto & ch : s){
               total += weights[ch - 'a'];
           }
           total = total % 26;
           ans.push_back(122 - total);
       }
       return ans;
   }
};
