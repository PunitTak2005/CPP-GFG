class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.size();

        // if n is equal to k, return true
        if (n == k)
            return true;

        // if n is not divisible by k, return false
        if (n % k != 0)
            return false;

        // mapping substrings of size k and their frequency
        unordered_map<string, int> m;
        for (int i = 0; i < n; i += k) {
            m[s.substr(i, k)]++;
        }

        // if only one unique substring is found
        if (m.size() == 1)
            return true;

        // if more than 2 unique substrings are found
        if (m.size() != 2)
            return false;

        // check frequencies
        int total = n / k;
        for (auto &it : m) {
            if (it.second == 1 || it.second == total - 1)
                return true;
        }

        return false;
    }
};
