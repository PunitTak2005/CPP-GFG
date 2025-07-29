class Solution {
  public:
    vector<int> asciirange(string& s) {
        if (s.empty()) return {};  // return empty if string is empty

        int min_ascii = INT_MAX;
        int max_ascii = INT_MIN;

        for (char c : s) {
            int ascii_val = (int)c;
            min_ascii = min(min_ascii, ascii_val);
            max_ascii = max(max_ascii, ascii_val);
        }

        return {min_ascii, max_ascii};
    }
};
