#include <iostream>
using namespace std;

// first name space
namespace first_space
{
   void func()
   {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space
{
   void func()
   {
      cout << "Inside second_space" << endl;
   }
}

using namespace first_space;

int main ()
{
    // This calls function from first name space.
   func();
   return 0;
}

// If we compile and run above code, this would produce the following result:
// Inside first_space
