// C++ program to demonstrate
// the problem with 'unsigned short'
#include <iostream>

using namespace std;

int main()
{
    unsigned short a;

    for (a = 65532; a < 65536; a++)
        cout << a << "\n";

    return 0;
}
