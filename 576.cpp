class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        // 1. Check single character repeats (Subsets of size 1)
        int currentRun = 1;
        for (int i = 1; i <= n; ++i) {
            if (i < n && s[i] == s[i-1]) {
                currentRun++;
            } else {
                maxLen = max(maxLen, currentRun);
                currentRun = 1;
            }
        }

        // 2. Check subsets of size 2 and 3
        vector<vector<char>> subsets = {
            {'a', 'b'}, {'a', 'c'}, {'b', 'c'}, // Size 2
            {'a', 'b', 'c'}                     // Size 3
        };

        for (auto& subset : subsets) {
            maxLen = max(maxLen, solveForSubset(s, subset));
        }

        return maxLen;
    }

private:
    int solveForSubset(const string& s, const vector<char>& subset) {
        unordered_set<char> allowed(subset.begin(), subset.end());
        int n = s.size();
        int best = 0;

        // We process segments of the string that ONLY contain characters from the subset
        for (int i = 0; i < n; ) {
            if (allowed.find(s[i]) == allowed.end()) {
                i++;
                continue;
            }

            int start = i;
            while (i < n && allowed.find(s[i]) != allowed.end()) {
                i++;
            }
            // s[start...i-1] is a segment containing only 'allowed' characters
            best = max(best, findBalancedInSegment(s, start, i - 1, subset));
        }
        return best;
    }

    int findBalancedInSegment(const string& s, int L, int R, const vector<char>& subset) {
        // Must contain ALL characters in the subset at least once to meet "distinct characters" rule
        int targetDistinct = subset.size();
        unordered_map<long long, int> firstSeen;
        
        // Key logic: 
        // For 2 chars (a, b): key = countA - countB
        // For 3 chars (a, b, c): key = {countA - countB, countA - countC}
        
        int counts[3] = {0, 0, 0}; // a, b, c
        auto getKey = [&]() -> long long {
            if (targetDistinct == 2) {
                // Return difference between the two specific characters
                int c1 = subset[0] - 'a', c2 = subset[1] - 'a';
                return counts[c1] - counts[c2];
            } else {
                // Pack differences (a-b) and (a-c)
                long long d1 = counts[0] - counts[1];
                long long d2 = counts[0] - counts[2];
                return (d1 << 32) | (unsigned int)d2;
            }
        };

        firstSeen[getKey()] = L - 1;
        int localMax = 0;
        
        // To ensure ALL characters in the subset are present
        // track the last seen position of each character
        vector<int> lastPos(3, -1);

        for (int i = L; i <= R; ++i) {
            counts[s[i] - 'a']++;
            lastPos[s[i] - 'a'] = i;

            long long key = getKey();
            if (firstSeen.count(key)) {
                int prevIdx = firstSeen[key];
                
                // VALIDATION: Does the substring (prevIdx, i] contain all characters in subset?
                bool allPresent = true;
                for (char c : subset) {
                    if (lastPos[c - 'a'] <= prevIdx) {
                        allPresent = false;
                        break;
                    }
                }
                
                if (allPresent) {
                    localMax = max(localMax, i - prevIdx);
                }
            } else {
                firstSeen[key] = i;
            }
        }
        return localMax;
    }
};
