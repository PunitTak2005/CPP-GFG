#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to lowercase a string
    string toLower(string s) {
        for (auto &c : s) c = tolower(c);
        return s;
    }

    // Function to replace vowels with '*'
    string maskVowels(string s) {
        for (auto &c : s) {
            char ch = tolower(c);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap; // lowercase match
        unordered_map<string, string> vowelMap; // vowel masked match

        // Preprocess wordlist
        for (auto &w : wordlist) {
            string lower = toLower(w);
            string masked = maskVowels(lower);

            if (!caseMap.count(lower)) caseMap[lower] = w;
            if (!vowelMap.count(masked)) vowelMap[masked] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q); // exact match
            } else {
                string lowerQ = toLower(q);
                string maskedQ = maskVowels(lowerQ);

                if (caseMap.count(lowerQ)) {
                    ans.push_back(caseMap[lowerQ]); // case-insensitive match
                } else if (vowelMap.count(maskedQ)) {
                    ans.push_back(vowelMap[maskedQ]); // vowel error match
                } else {
                    ans.push_back(""); // no match
                }
            }
        }

        return ans;
    }
};
