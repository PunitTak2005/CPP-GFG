class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, 
                                   vector<string>& businessLine, 
                                   vector<bool>& isActive) {
        vector<string> result;
        
        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isActive[i] && !businessLine[i].empty()) {
                result.push_back("VALID: " + code[i] + " (" + businessLine[i] + ")");
            } else {
                result.push_back("INVALID: " + code[i]);
            }
        }
        
        return result;
    }
};
