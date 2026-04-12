#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) {
            cout << "5 found in array";
            break;
        }
    }
    return 0;
}
