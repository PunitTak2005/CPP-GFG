#include <bits/stdc++.h>
using namespace std;

int main()
{
    // a: 1100, b: 0110, c: 0010, d: 1001,e: 0001
    int a = 12, b = 6, c = 2, d = 9, e = 1;
    
    a &= b;
    //   1100
    // & 0110
    //-------
    //   0100 (4)
    cout << "AND & Assign: "<< a <<"\n";
    
    a |= c;
    //   0100
    // | 0010
    //-------
    //   0110 (6)
    cout << "OR & Assign: " << a << "\n";
    
    a ^= d;
    //   0110
    // ^ 1001
    //-------
    //   1111 (15)
    cout << "XOR & Assign: " << a << "\n";
    
    a <<= e;
    //    1111
    // << 0001
    //--------
    //   11110 (30)
    cout << "Left-shift & Assign: " << a << "\n"; 
    
    a >>= e;
    //    11110
    // >> 00001
    //---------
    //    01111 (15)
    cout << "Right-shift & Assign: " << a << "\n";
    
    return 0;
}
