class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        int n = arr.size();
        vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = good

        function<bool(int)> dfs = [&](int i) -> bool {
            if (i < 0 || i >= n) return true;      // escaped
            if (state[i] == 2) return true;        // already known good
            if (state[i] == 1) return false;       // cycle found

            state[i] = 1;
            bool good = dfs(i + arr[i]);
            state[i] = good ? 2 : 1;
            return good;
        };

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dfs(i)) count++;
        }
        return count;
    }
};
