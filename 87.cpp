// C++ program to illustrate do-while loop
#include <iostream>
using namespace std;

int main()
{
    int i = 2; // Initialization expression

    do
    {
        // loop body
        cout << "Hello World\n";

        // update expression
        i++;

    }  while (i < 1);   // test expression

    return 0;
}
