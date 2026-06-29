class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (string &p : patterns) {
            // if p exists as a substring in word
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        return count;
    }
};
