// C++ program to demonstrate working of trunc()
// in C/C++
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
    double x = 1.411, y = 1.500, z = 1.611;
    cout << trunc(x) << endl;
    cout << trunc(y) << endl;
    cout << trunc(z) << endl;

    double a = -1.411, b = -1.500, c = -1.611;
    cout << trunc(a) << endl;
    cout << trunc(b) << endl;
    cout << trunc(c) << endl;
    return 0;
}
