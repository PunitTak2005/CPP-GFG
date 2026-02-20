class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;

        // Split into top-level special substrings
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') ++count;
            else --count;

            // when count == 0 we closed a special substring
            if (count == 0) {
                // inner part without outer '1' and '0'
                string inner = s.substr(start + 1, i - start - 1);
                // recursively make this inner part largest
                inner = makeLargestSpecial(inner);
                // rebuild this block: '1' + inner + '0'
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // sort blocks in descending lexicographical order
        sort(parts.begin(), parts.end(), greater<string>());

        // concatenate
        string res;
        for (auto &p : parts) res += p;
        return res;
    }
};
