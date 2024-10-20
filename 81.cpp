//Following Member-Access Operators can be demonstrated 
//using structures only. Please proceed to the main() part
//of the code as structure declaration will be covered later
#include <bits/stdc++.h>
using namespace std;

struct test
{
    int x;
    int *p;
};

int main()
{
    struct test t;
    struct test *ptr_t = &t;
    
    t.x = 5;
    
    int b = 10;
    t.p = &b;
    
    cout << "Direct Access: " << t.x << endl;
    cout << "Pointer Access: " << ptr_t->x <<endl;
    
    cout << "Direct Access of Pointer: " << *(t.p) << endl;
    cout << "Pointer Access of Pointer: " << *(ptr_t->p) << endl;
}
