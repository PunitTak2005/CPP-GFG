//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string findOrder(vector<string>& w) {
        unordered_map<char,int> i;
        unordered_map<char,unordered_set<char>> g;
        for(auto &x : w) {
            for(auto c : x) {
                i[c] = 0;
                g[c];
            }
        }
        int n = w.size();
        for(int a = 0; a < n - 1; a++){
            string s = w[a], t = w[a+1];
            int m = min(s.size(), t.size());
            bool f = false;
            for(int b = 0; b < m; b++){
                if(s[b] != t[b]){
                    if(g[s[b]].find(t[b]) == g[s[b]].end()){
                        g[s[b]].insert(t[b]);
                        i[t[b]]++;
                    }
                    f = true;
                    break;
                }
            }
            if(!f && s.size() > t.size()) return "";
        }
        queue<char> q;
        for(auto &p : i) if(p.second == 0) q.push(p.first);
        string r;
        while(!q.empty()){
            char c = q.front();
            q.pop();
            r.push_back(c);
            for(auto d : g[c]){
                i[d]--;
                if(i[d] == 0) q.push(d);
            }
        }
        if(r.size() != i.size()) return "";
        return r;
       
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
