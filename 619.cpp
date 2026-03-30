class Solution {
  public:
    int minCost(vector<vector<int>> &houses) {
        int n = houses.size();
        vector<int> d(n, INT_MAX);
        vector<bool> vis(n, false);

        d[0] = 0;
        int ans = 0;

        for (int it = 0; it < n; ++it) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!vis[i] && (u == -1 || d[i] < d[u])) u = i;
            }

            vis[u] = true;
            ans += d[u];

            for (int v = 0; v < n; ++v) {
                if (!vis[v]) {
                    int w = abs(houses[u][0] - houses[v][0]) +
                            abs(houses[u][1] - houses[v][1]);
                    if (w < d[v]) d[v] = w;
                }
            }
        }
        return ans;
    }
};
