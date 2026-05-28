class Solution {
public:
    struct Node {
        int nxt[26];
        int bestIdx;     // index in wordsContainer with best candidate for this suffix
        Node() {
            memset(nxt, -1, sizeof(nxt));
            bestIdx = -1;
        }
    };

    vector<Node> trie;

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.push_back(Node());  // root

        int n = wordsContainer.size();

        // Helper lambda to update best index at a node
        auto better = [&](int curIdx, int newIdx) {
            if (curIdx == -1) return true;
            const string &a = wordsContainer[curIdx];
            const string &b = wordsContainer[newIdx];
            if (b.size() < a.size()) return true;
            if (b.size() > a.size()) return false;
            return newIdx < curIdx;    // same length, earlier index is better
        };

        // Build trie with reversed wordsContainer
        for (int i = 0; i < n; ++i) {
            const string &w = wordsContainer[i];
            int node = 0;

            // update best at root for empty suffix
            if (better(trie[node].bestIdx, i)) {
                trie[node].bestIdx = i;
            }

            // insert reversed characters
            for (int j = (int)w.size() - 1; j >= 0; --j) {
                int c = w[j] - 'a';
                if (trie[node].nxt[c] == -1) {
                    trie[node].nxt[c] = (int)trie.size();
                    trie.push_back(Node());
                }
                node = trie[node].nxt[c];

                // update best index for this suffix node
                if (better(trie[node].bestIdx, i)) {
                    trie[node].bestIdx = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        // Answer queries
        for (const string &q : wordsQuery) {
            int node = 0;
            int best = trie[node].bestIdx;  // empty suffix always possible

            for (int j = (int)q.size() - 1; j >= 0; --j) {
                int c = q[j] - 'a';
                if (trie[node].nxt[c] == -1) break;  // cannot extend suffix
                node = trie[node].nxt[c];
                best = trie[node].bestIdx;
            }

            ans.push_back(best);
        }

        return ans;
    }
};
