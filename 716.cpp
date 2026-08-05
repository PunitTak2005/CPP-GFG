class Solution {
  public:
    int countSub(vector<int>& arr, int x) {

        int n = arr.size();

        int st = 0;
        int end = 0;

        int sum = 0;
        int cnt = 0;

        while (end < n) {

            sum += arr[end];

            while (st <= end && sum > x) {
                sum -= arr[st];
                st++;
            }

            cnt += (end - st + 1);

            end++;
        }

        return cnt;
    }

    int countSubarray(vector<int>& arr, int l, int r) {

        int rcnt = countSub(arr, r);

        int lcnt = countSub(arr, l - 1);

        return rcnt - lcnt;
    }
};
