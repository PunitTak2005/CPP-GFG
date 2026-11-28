#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool checkPath(vector<vector<int>>& adj, int u, int v) {
        if (u == v) return true;

        int n = static_cast<int>(adj.size());
        vector<bool> visited(n, false);
        queue<int> q;

        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nxt : adj[curr]) {
                if (nxt == v) return true;
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        return false;
    }
};
