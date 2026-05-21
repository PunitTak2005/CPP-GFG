class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Step 1: Extract and store all prefixes from arr1
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; // Removes the last digit to get the next prefix
            }
        }
        
        int maxLength = 0;
        
        // Step 2: Check prefixes of elements in arr2 against the set
        for (int val : arr2) {
            while (val > 0) {
                // If the prefix exists in the set
                if (prefixes.count(val)) {
                    // Calculate the number of digits (length) of this prefix
                    int currentLength = to_string(val).length();
                    maxLength = max(maxLength, currentLength);
                    break; // Since we go from largest to smallest prefix, we can stop for this number
                }
                val /= 10;
            }
        }
        
        return maxLength;
    }
};
