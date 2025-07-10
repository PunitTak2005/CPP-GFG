// trie node definition
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
  public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        // marking the end of the word
        node->isEnd = true;
    }

    // check if all prefixes of the word exist in the trie
    bool allPrefixesExist(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];

            // if the prefix is missing or not marked as end
            if (!node || !node->isEnd) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
  public:
    string longestString(vector<string>& arr) {
        Trie trie;

        // insert all words into the trie
        for (string& word : arr) {
            trie.insert(word);
        }

        string result = "";

        // check each word
        for (string& word : arr) {

            // if all prefixes exist
            if (trie.allPrefixesExist(word)) {

                // update result if word is longer or
                // lexicographically smaller
                if (word.length() > result.length() ||
                    (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};
