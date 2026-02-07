class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;      // number of 'b's seen so far
        int deletions = 0;   // minimum deletions up to current index
        
        for (char c : s) {
            if (c == 'b') {
                // keeping this 'b' may cause future "ba" pairs,
                // but we can delete it later if needed
                bCount++;
            } else { // c == 'a'
                // two options:
                // 1) delete this 'a' -> deletions + 1
                // 2) delete all previous 'b's -> bCount
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;
    }
};
