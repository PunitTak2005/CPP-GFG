class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        unordered_map<long long, pair<int, int>> seen;
        seen.reserve(n * n / 2);

        vector<int> best;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long sum = 1LL * arr[i] + arr[j];
                auto it = seen.find(sum);

                if (it != seen.end()) {
                    int a = it->second.first;
                    int b = it->second.second;

                    // Ensure all four indices are distinct
                    if (a != i && a != j && b != i && b != j) {
                        vector<int> candidate = {a, b, i, j};
                        if (best.empty() || candidate < best) {
                            best = candidate;
                        }
                    }
                } else {
                    // Store the lexicographically first pair for this sum
                    seen[sum] = {i, j};
                }
            }
        }

        return best.empty() ? vector<int>{-1, -1, -1, -1} : best;
    }
};
