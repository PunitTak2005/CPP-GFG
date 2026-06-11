class Solution {
  public:
    int findIndex(string &s) {
        int total_closing = 0;
        for(char c : s) {
            if(c == ')') total_closing++;
        }
        return total_closing;
    }
};
