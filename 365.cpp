class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {

        int n = a.size(), m = b.size();
        // to store the result
        vector<int> res(n);

        int maxi = *max_element(b.begin(), b.end());

        // to store frequency of elements in b[]
        vector<int> cnt(maxi + 1, 0);
        for (int i = 0; i < m; i++) {
            cnt[b[i]]++;
        }

        // transform cnt[] to prefix sum array
        for (int i = 1; i < maxi + 1; i++) {
            cnt[i] += cnt[i - 1];
        }

        // loop for each element of a[]
        for (int i = 0; i < n; i++) {
            res[i] = cnt[min(a[i], maxi)];
        }

        return res;
    }
};
