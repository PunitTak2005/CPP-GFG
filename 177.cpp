
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();   
        int count = 0;
    
        // Iterate for the first element of the triplet
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1; // Second pointer
            int k = n - 1; // Third pointer
    
            // Two-pointer approach
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target) {
                    // Handle duplicates for the second and third elements
                    if (arr[j] == arr[k]) {
                        int numElements = k - j + 1;
                        count += (numElements * (numElements - 1)) / 2; // nC2 pairs
                        break; // All pairs are processed
                    } else {
                        int leftCount = 1, rightCount = 1;
                        while (j + 1 < k && arr[j] == arr[j + 1]) {
                            leftCount++;
                            j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k - 1]) {
                            rightCount++;
                            k--;
                        }
                        count += leftCount * rightCount;
                        j++;
                        k--;
                    }
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
};


vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}
