class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c : n) {
            int d = c - '0';
            if (d > ans) ans = d;
        }
        return ans;
    }
};
