class Solution {
  private:
    static bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

  public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> freq;
        int prefix = 0;
        long long res = 0; // use long long to accumulate safely

        freq[0] = 1; // empty prefix

        for (const string& s : arr) {
            int score = 0;
            for (char ch : s) {
                if (isVowel(ch))
                    score += 1;
                else
                    score -= 1;
            }
            prefix += score;
            if (freq.count(prefix))
                res += freq[prefix];
            freq[prefix]++;
        }

        return static_cast<int>(res);
    }
};
