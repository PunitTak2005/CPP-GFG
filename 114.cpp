#include <iostream>
using namespace std;

// First namespace
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}

// Second namespace
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}

int main() {
    // Calling the function from the first namespace
    first_space::func();
    
    // Calling the function from the second namespace
    second_space::func();
    
    return 0;
}
