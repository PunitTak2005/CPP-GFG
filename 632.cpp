class Solution {
public:
    bool rotateString(string s, string goal) {
        // First check if lengths are equal (necessary condition)
        // Then check if goal appears in s+s (sufficient condition)
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};
