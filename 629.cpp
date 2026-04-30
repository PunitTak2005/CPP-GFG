class Solution {
public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // Check all internal nodes: indices 0 to n/2 - 1
        for (int i = 0; i <= (n / 2) - 1; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // If left child exists and is greater than parent
            if (left < n && arr[i] < arr[left]) return false;

            // If right child exists and is greater than parent
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }
};
