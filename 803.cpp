class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> diff(n + 1, 0);

        for (int j : updates) {
            diff[j]++;   // update affects indices 1..j
        }

        vector<int> arr(n);
        int add = 0;

        for (int i = 1; i <= n; i++) {
            add += diff[i];
            arr[i - 1] = add;
        }

        return arr;
    }
};
