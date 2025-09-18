class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;   // count of unmatched '('
        int close = 0;  // count of unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                open++;  // one more '(' waiting for a ')'
            } else if (c == ')') {
                if (open > 0) {
                    open--;  // match with a previous '('
                } else {
                    close++; // extra ')' that needs '('
                }
            }
        }
        
        // total unmatched parentheses
        return open + close;
    }
};
