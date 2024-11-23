#include<iostream>
using namespace std;

int global = 5;

void display() {
    cout << global << endl;
}

int main() {
    display(); // Displays 5

    global = 10;
    display(); // Displays 10

    return 0;
}
