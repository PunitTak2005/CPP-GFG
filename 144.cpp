#include <iostream>
#include <vector>

using namespace std;

void sort012(vector<int>& arr) {
  int low = 0, mid = 0, high = arr.size() - 1;

  // Traverse the array and sort it using three pointers
  while (mid <= high) {
    switch (arr[mid]) {
      case 0:
        // Swap arr[low] and arr[mid], increment low and mid
        swap(arr[low], arr[mid]);
        low++;
        mid++;
        break;

      case 1:
        // Move mid pointer ahead
        mid++;
        break;

      case 2:
        // Swap arr[mid] and arr[high], decrement high
        swap(arr[mid], arr[high]);
        high--;
        break;
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort012(arr);

    for (int num : arr) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
