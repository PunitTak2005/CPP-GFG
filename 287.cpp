class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = n * 2;

        // min distance for positions in [0, 2n)
        vector<int> minDist(m, m);

        // pass 1: left-to-right, nearest same value to the left
        unordered_map<int, int> last;
        last.reserve(n * 2);
        for (int i = 0; i < m; ++i) {
            int x = nums[i % n];
            auto it = last.find(x);
            if (it != last.end()) {
                int d = i - it->second;
                if (d < minDist[i]) minDist[i] = d;
            }
            last[x] = i;
        }

        // pass 2: right-to-left, nearest same value to the right
        unordered_map<int, int> nextPos;
        nextPos.reserve(n * 2);
        for (int i = m - 1; i >= 0; --i) {
            int x = nums[i % n];
            auto it = nextPos.find(x);
            if (it != nextPos.end()) {
                int d = it->second - i;
                if (d < minDist[i]) minDist[i] = d;
            }
            nextPos[x] = i;
        }

        // merge distances for i and i+n (for circular wrap)
        for (int i = 0; i < n; ++i) {
            minDist[i] = min(minDist[i], minDist[i + n]);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            int d = minDist[q];
            if (d >= n) d = -1;   // no other equal element
            ans.push_back(d);
        }
        return ans;
    }
};
