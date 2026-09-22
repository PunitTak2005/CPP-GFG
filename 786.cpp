class Solution {
public:
    string findLongestWord(string& s, vector<string>& d) {
        int n = s.size();
        // nextPos[i][c] = first index >= i where char c appears, or -1
        vector<array<int, 26>> nextPos(n + 1);
        
        // Initialize last row with -1
        for (int c = 0; c < 26; ++c) {
            nextPos[n][c] = -1;
        }
        
        // Build from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int c = 0; c < 26; ++c) {
                nextPos[i][c] = nextPos[i + 1][c];
            }
            nextPos[i][s[i] - 'a'] = i;
        }
        
        string ans = "";
        
        for (const string& word : d) {
            int pos = 0;
            bool ok = true;
            
            for (char ch : word) {
                int c = ch - 'a';
                if (pos > n || nextPos[pos][c] == -1) {
                    ok = false;
                    break;
                }
                pos = nextPos[pos][c] + 1;
            }
            
            if (!ok) continue;
            
            if ((int)word.size() > (int)ans.size()) {
                ans = word;
            } else if ((int)word.size() == (int)ans.size()) {
                if (word < ans) {
                    ans = word;
                }
            }
        }
        
        return ans;
    }
};
