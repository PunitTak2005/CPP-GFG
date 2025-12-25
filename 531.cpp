class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        long long dec = 0; // how many times we've already decremented

        for (int i = 0; i < k; ++i) {
            long long val = happiness[i] - dec;
            if (val <= 0) break;   // no further contributions will be positive
            ans += val;
            ++dec;
        }
        return ans;
    }
};
