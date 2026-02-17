class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                // __builtin_popcount counts number of 1 bits in an int
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // format minute with two digits
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};
