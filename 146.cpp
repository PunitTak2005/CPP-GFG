//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to merge two sorted halves and count inversions
    void merge(int low, int mid, int high, vector<int>& arr, int& cnt) {
        int size = high - low + 1;
        vector<int> temp(size); // Temporary array for merging
        int left = low, right = mid + 1, k = 0;

        // Merge the two halves while counting inversions
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                cnt += (mid - left + 1); // Count inversions
                temp[k++] = arr[right++];
            }
        }

        // Copy remaining elements from the left half
        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        // Copy remaining elements from the right half
        while (right <= high) {
            temp[k++] = arr[right++];
        }

        // Copy the merged array back into the original array
        for (int i = 0; i < size; i++) {
            arr[low + i] = temp[i];
        }
    }

    // Recursive function to divide the array and count inversions
    void divide(int low, int high, vector<int>& arr, int& cnt) {
        if (low >= high) return; // Base case: single element

        int mid = (low + high) / 2;
        divide(low, mid, arr, cnt);       // Left half
        divide(mid + 1, high, arr, cnt); // Right half
        merge(low, mid, high, arr, cnt); // Merge and count inversions
    }

    // Main function to count inversions in the array
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0; // Initialize inversion count
        divide(0, n - 1, arr, cnt);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline after the number of test cases

    while (T--) {
        vector<int> a;
        string input;
        getline(cin, input); // Read the array as a line of input
        stringstream ss(input);
        int num;
        while (ss >> num) {
            a.push_back(num); // Parse input into the vector
        }

        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
