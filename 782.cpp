class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int half = n / 2;
        
        // Extract and sort the second half
        vector<int> secondHalf;
        secondHalf.reserve(half);
        for (int i = half; i < n; ++i) {
            secondHalf.push_back(arr[i]);
        }
        sort(secondHalf.begin(), secondHalf.end());
        
        long long count = 0;
        
        for (int i = 0; i < half; ++i) {
            // Proper floor division for negative numbers
            int limit;
            if (arr[i] >= 0) {
                limit = arr[i] / 5;
            } else {
                // For negative: floor(arr[i]/5) = (arr[i] - 4) / 5
                limit = (arr[i] - 4) / 5;
            }
            
            auto it = upper_bound(secondHalf.begin(), secondHalf.end(), limit);
            count += (it - secondHalf.begin());
        }
        
        return (int)count;
    }
};
