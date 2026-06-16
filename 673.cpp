class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        using namespace std;

        // Deduced 'q' from the size of the queries vector
        int q = queries.size();

        // Store cumulative Bitwise XOR
        int xr = 0;

        // Initialize final list to return
        vector<int> ans;

        // Perform each query processing in reverse order
        for (int i = q - 1; i >= 0; i--) {
            if (queries[i][0] == 0) {
                ans.push_back(queries[i][1] ^ xr);
            } else {
                xr ^= queries[i][1];
            }
        }

        // The initial value of 0 (XORed with all type 1 queries)
        ans.push_back(xr);

        // Sort the list as required by the problem statement
        sort(ans.begin(), ans.end());

        // Return final list
        return ans;
    }
};
