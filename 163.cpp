//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
  int n = mat.size();
        int m = n;
        for(int i=0;i<n;i++)//rows
        {
            for(int j=i;j<n;j++)//columns
            {
                swap(mat[j][i],mat[i][j]);
            }
            
        }
        int start = 0,end=n-1;
        while(start<end)
        {
            for(int j=0;j<n;j++)
            {
                swap(mat[start][j],mat[end][j]);
            }
            start++;end--;
        }
        


    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends