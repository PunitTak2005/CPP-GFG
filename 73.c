// C++ program  to demonstrate syntax of switch
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    char x = 'A';
    switch (x) {
    case 'A':
        cout << "Choice is A";
        break;
    case 'B':
        cout << "Choice is B";
        break;
    case 'C':
        cout << "Choice is C";
        break;
    default:
        cout << "Choice other than A, B and C";
        break;
    }
    return 0;
}
