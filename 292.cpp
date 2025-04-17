//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



// User function template for C++
class TrieNode{
    public:
    TrieNode* child[26];
    bool isEndofWord;
    TrieNode(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isEndofWord=false;
    }
};
class Trie {
  public:
    TrieNode* root;
    Trie() {
        // implement Trie
        root=new TrieNode();
        
    }

    void insert(string &word) {
        // insert word into Trie
         TrieNode* node=root;
         for(char c:word){
             int idx=c-'a';
             if(node->child[idx]==NULL){
                 node->child[idx]=new TrieNode();
                 node=node->child[idx];
             }else node=node->child[idx];
         }
         node->isEndofWord=true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* node=root;
         for(char c:word){
             int idx=c-'a';
             if(node->child[idx]==NULL) return 0;
             node=node->child[idx];
             
         }return node->isEndofWord;
        
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* node=root;
         for(char c:word){
             int idx=c-'a';
             if(node->child[idx]==NULL) return 0;
             node=node->child[idx];
             
         }
         return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
