class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        
        vector<int> m1(256, -1), m2(256, -1);
        
        for (int i = 0; i < (int)s1.size(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            if (m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;     // map c1 -> c2
                m2[c2] = c1;     // map c2 -> c1
            } else {
                // existing mapping must be consistent both ways
                if (m1[c1] != c2 || m2[c2] != c1) return false;
            }
        }
        return true;
    }
};
