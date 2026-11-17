class Solution {
public:
    bool findPattern(string &s) {
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            int countX = 0;
            // Count consecutive 'x's
            while (i < n && s[i] == 'x') {
                countX++;
                i++;
            }
            
            int countY = 0;
            // Count consecutive 'y's
            while (i < n && s[i] == 'y') {
                countY++;
                i++;
            }
            
            // If there are no 'x's, or the count of 'x' and 'y' don't match
            if (countX == 0 || countX != countY) {
                return false;
            }
        }
        
        return true;
    }
};
