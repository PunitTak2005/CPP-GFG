//Program to demonstrate
//Logical Operators
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool a = true, b = false;
    
    //negate a boolean
    cout << "Negation: " << !a << endl;
    
    //logical AND
    cout << "AND: " << (a && b) << endl;
    
    //logical OR
    cout << "OR: " << (a || b) << endl;
    
    //Some examples using expressions
    int x = 5, y = 6, z = 5;
    
    //x is not equal to y, but negation yields true
    cout << !(x == y) << endl;
    
    //x is smaller than y, AND yields false
    //despite x==z being true
    cout << ((x > y) && (x == z)) << endl;
    
    //x is smaller than y, but x==z is true,
    //OR yields true
    cout << ((x > y) || (x == z)) << endl;
    
    return 0;
}
