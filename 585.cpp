class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int need = 1 << k;              // total different codes of length k
        vector<bool> seen(need, false); // marks which codes we've seen
        int allOnes = need - 1;         // mask to keep only last k bits
        int hash = 0;

        // build initial hash for first k - 1 chars
        for (int i = 0; i < k - 1; ++i) {
            hash = ((hash << 1) & allOnes) | (s[i] - '0');
        }

        // slide window, updating hash in O(1)
        for (int i = k - 1; i < n; ++i) {
            hash = ((hash << 1) & allOnes) | (s[i] - '0');
            if (!seen[hash]) {
                seen[hash] = true;
                --need;
                if (need == 0) return true;
            }
        }

        return false;
    }
};
