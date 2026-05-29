class Solution {
public:
    int validGroups(string& s) {
        int n = s.size();
        map<pair<int, int>, int> memo;
        return solve(0, 0, s, n, memo);
    }
    
private:
    int solve(int idx, int prevSum, string& s, int n, 
              map<pair<int, int>, int>& memo) {
        // Base case: reached end
        if (idx == n) return 1;
        
        // Check memo
        auto key = make_pair(idx, prevSum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int count = 0;
        int currentSum = 0;
        
        // Try all substring lengths from current position
        for (int i = idx; i < n; i++) {
            currentSum += (s[i] - '0');
            
            // If valid (non-decreasing), recurse
            if (currentSum >= prevSum) {
                count += solve(i + 1, currentSum, s, n, memo);
            }
        }
        
        memo[key] = count;
        return count;
    }
};
