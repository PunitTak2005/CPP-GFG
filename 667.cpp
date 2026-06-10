class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] == sorted[i]) cnt++;
        
        return cnt;
    }
};
