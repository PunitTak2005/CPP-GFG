#include <iostream>
using namespace std;

int main() {
    char x = 'a';  
    switch (x) {
        case 'a':
            cout << "Choice is A";
            break;
        case 'b':
            cout << "Choice is B";
            break;
        case 'c':
            cout << "Choice is C";
            break;
        default:
            cout << "Choice other than A, B and C";  
            break;
    }
    return 0;
}
