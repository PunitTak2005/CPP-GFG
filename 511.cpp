class Solution {
public:
    struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    void insert(Trie* root, int num) {
        for (int i = 15; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!root->child[bit])
                root->child[bit] = new Trie();
            root = root->child[bit];
            root->cnt++;
        }
    }

    // Count numbers already in trie such that (num XOR x) < k
    int countLess(Trie* root, int num, int k) {
        int ans = 0;
        for (int i = 15; i >= 0; i--) {
            if (!root) return ans;

            int bitNum = (num >> i) & 1;
            int bitK = (k >> i) & 1;

            if (bitK == 1) {
                // If k bit is 1:
                // we can take child[bitNum] (matching bit) fully
                if (root->child[bitNum])
                    ans += root->child[bitNum]->cnt;

                // and move to opposite branch
                root = root->child[bitNum ^ 1];
            } else {
                // If k bit is 0:
                // we must follow the same bitNum direction
                root = root->child[bitNum];
            }
        }
        return ans;
    }

    int cntPairs(vector<int>& arr, int k) {
        Trie* root = new Trie();
        int ans = 0;

        for (int x : arr) {
            ans += countLess(root, x, k);
            insert(root, x);
        }
        return ans;
    }
};
