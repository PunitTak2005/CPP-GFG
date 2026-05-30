class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        
        // Store original values since we need them for XOR calculations
        vector<int> original = arr;
        
        // First element: arr[0] ^ arr[1]
        result[0] = original[0] ^ original[1];
        
        // Last element: arr[n-2] ^ arr[n-1]
        result[n-1] = original[n-2] ^ original[n-1];
        
        // Middle elements: arr[i-1] ^ arr[i+1]
        for (int i = 1; i < n - 1; i++) {
            result[i] = original[i-1] ^ original[i+1];
        }
        
        // Update original array
        arr = result;
    }
};
