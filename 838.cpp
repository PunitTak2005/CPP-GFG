class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        long long totalDegree = 0;
        for (const auto& neighbors : adj) {
            totalDegree += static_cast<long long>(neighbors.size());
        }
        return static_cast<int>(totalDegree / 2);
    }
};
