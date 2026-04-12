#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    //access 3rd element
    cout << "4th element of the array (0-indexing): "  << a[3] << endl;
    
    int b = 6, *p = &b;
    
    //access value using pointer
    cout << "Access via Pointer: " << *p << endl;
    *p = 5;
    cout << "Value changed via pointer: " << b << endl;
    
    //Access address of b
    cout << "Address of b: " << &b << endl;
    
    return 0;
}
