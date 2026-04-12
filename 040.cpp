// Example of 'SIGABRT' error

#include <iostream>
using namespace std;

int main() {

    int arr[5] = {1, 2, 3, 4, 5};
  
    // SIGABRT error
    arr[6] = 6;
  
    return 0;
}
