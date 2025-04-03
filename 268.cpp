//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        int dd[5] = {0, -1, 0, 1, 0};
        queue<pair<int, int>>q;
        int freshCnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) mat[i][j] == -1;
                else if(mat[i][j] == 1) mat[i][j] = INT_MAX, freshCnt++;
                else mat[i][j] = 0, q.push({i, j});
            }
        }
        if(!freshCnt) return 0;
        int mini = 0;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second; q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dd[k], ny = y + dd[k+1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == INT_MAX){
                    mat[nx][ny] = 1 + mat[x][y];
                    mini = max(mini, mat[nx][ny]);
                    q.push({nx, ny});
                    freshCnt--;
                }
            }
        }
        return freshCnt ? -1 : mini;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
