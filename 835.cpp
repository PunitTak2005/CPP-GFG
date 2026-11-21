class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        // closest[c] holds the nearest ancestor on the current DFS path with character 'a' + c
        vector<int> closest(26, -1);
        vector<int> finalParent(parent);

        auto assignParents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prevClosest = closest[c];

            if (u != 0 && prevClosest != -1) {
                finalParent[u] = prevClosest;
            }

            closest[c] = u;
            for (int v : origAdj[u]) {
                self(self, v);
            }
            closest[c] = prevClosest; // Backtrack
        };

        assignParents(assignParents, 0);

        // Build the final tree using finalParent
        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[finalParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto computeSubtreeSize = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : finalAdj[u]) {
                size += self(self, v);
            }
            return ans[u] = size;
        };

        computeSubtreeSize(computeSubtreeSize, 0);
        return ans;
    }
};
