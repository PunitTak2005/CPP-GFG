class Solution {
  public:
    int count(int mask, int k, vector<int>& freq, vector<int>& dp) {
    
    // All vowels used
    if (mask == (1 << k) - 1) {
        return 1;
    }

    // Return cached result if already computed
    if (dp[mask] != -1) {
        return dp[mask];
    }

    int total = 0;

    // Try each unused vowel
    for (int i = 0; i < k; i++) {
        if ((mask & (1 << i)) == 0) {
    
            // Choose one occurrence of vowel i and recurse
            total += freq[i] * count(mask | (1 << i), k, freq, dp);
        }
    }

    dp[mask] = total;
    return total;
}

int vowelCount(string &s) {
    string v = "aeiou";
    unordered_map<char, int> f;

    // Count frequency of each vowel in the string
    for (char c : s) {
        if (v.find(c) != string::npos) {
            f[c]++;
        }
    }

    vector<int> freq;

    // Build frequency list of distinct vowels in order
    for (char ch : v) {
        if (f.find(ch) != f.end()) {
            freq.push_back(f[ch]);
        }
    }

    int k = freq.size();
    if (k == 0) {
    
        // No vowels found
        return 0;
    }

    // Memoization table to store results for each mask
    vector<int> dp(1 << k, -1);
    return count(0, k, freq, dp);
}

};
