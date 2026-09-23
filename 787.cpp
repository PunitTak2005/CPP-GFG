class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        
        // Maximum valid pyramid height ending at i
        vector<int> left(n), right(n);
        
        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }
        
        // Maximum valid pyramid height starting at i
        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }
        
        long long originalSum = 0, maxPyramidSum = 0;
        for (int x : arr) originalSum += x;
        
        // Choose every position as a potential peak
        for (int peak = 0; peak < n; peak++) {
            long long currSum = 0;
            
            // Build left half including peak
            int height = min(left[peak], right[peak]);
            currSum += height;
            
            int required = height - 1;
            for (int i = peak - 1; i >= 0 && required > 0; i--, required--) {
                if (arr[i] < required) break;
                currSum += required;
            }
            
            required = height - 1;
            for (int i = peak + 1; i < n && required > 0; i++, required--) {
                if (arr[i] < required) break;
                currSum += required;
            }
            
            maxPyramidSum = max(maxPyramidSum, currSum);
        }
        
        return originalSum - maxPyramidSum;
    }
};
