//Program to demonstrate
//comparison operators
//Output produced is 0(false) or 1(true)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5, b = 6, c = 6;
    
    //check equality
    cout << "a == b: " << (a == b) << endl;
    
    //check inequality
    cout << "a != b: " << (a != b) << endl;
    
    //check less-than
    cout << "a < b: " << (a < b) << endl;
    
    //check greater-than
    cout << "a > b: " << (a > b) << endl;
    
    //check less-than-or-equal-to
    cout << "a <= c: " << (a <= c) << endl;
    
    //check greater-than-or-equal-to
    cout << "b >= c: " << (b >= c) << endl;
    
    return 0;
}
