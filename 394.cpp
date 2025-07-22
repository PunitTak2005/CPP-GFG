


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Helper function to segregate non-positive numbers to the beginning
    int segregateArr(vector<int>& arr) {
        int j = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j;
    }

    // Helper function to find the smallest missing positive number
    int findMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int val = abs(arr[i]);
            if (val - 1 < n && arr[val - 1] > 0) {
                arr[val - 1] = -arr[val - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }

    // Main function
    int missingNumber(vector<int>& arr) {
        int shift = segregateArr(arr);
        vector<int> positiveSubarray(arr.begin() + shift, arr.end());
        return findMissingPositive(positiveSubarray);
    }
};

// Example main function for testing
int main() {
    Solution ob;
    vector<int> arr = {0, -10, 1, 3, -20};
    int result = ob.missingNumber(arr);
    cout << "Smallest missing positive number: " << result << endl;
    return 0;
}
