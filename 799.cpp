class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        long long windowSum = 0;
        int left = 0;
        int answer = 1;

        for (int right = 0; right < arr.size(); right++) {
            windowSum += arr[right];

            long long required =
                1LL * arr[right] * (right - left + 1) - windowSum;

            while (required > k) {
                windowSum -= arr[left];
                left++;

                required =
                    1LL * arr[right] * (right - left + 1) - windowSum;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
