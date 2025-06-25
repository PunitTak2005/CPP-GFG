#include <unordered_map>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Count how many times each frequency appears
        unordered_map<int, int> freqCount;
        for (auto& it : freq) {
            freqCount[it.second]++;
        }

        // Case 1: All characters already have the same frequency
        if (freqCount.size() == 1) return true;

        // Case 2: Try removing one occurrence of a character
        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            // Check if we can remove one character to make frequencies same
            if ((c1 == 1 && (f1 - 1 == f2 || f1 - 1 == 0)) ||
                (c2 == 1 && (f2 - 1 == f1 || f2 - 1 == 0))) {
                return true;
            }
        }

        return false;
    }
};
