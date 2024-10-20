// A simple C++ program that uses getline to read
// input with blank lines
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    string str;
    int t = 4;
    while (t--) {
        getline(cin, str);

        // Keep reading a new line while there is
        // a blank line
        while (str.length() == 0)
            getline(cin, str);

        cout << str << " : newline" << endl;
    }
    return 0;
}
