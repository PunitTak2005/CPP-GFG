#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        vector<int> citationBuckets(papers + 1, 0);

        // Counting the number of papers in each citation bucket
        for (int c : citations) {
            if (c >= papers) {
                citationBuckets[papers]++;
            } else {
                citationBuckets[c]++;
            }
        }

        int cumulativePapers = 0;
        // Iterating from highest possible h-index to lowest
        for (int h = papers; h >= 0; h--) {
            cumulativePapers += citationBuckets[h];
            // Checking if current h-index is satisfied
            if (cumulativePapers >= h) {
                return h;
            }
        }
        return 0; // Return 0 if no h-index is found
    }
};
