#include <iostream>
using namespace std;

void printMessage() {
  cout << "Hello, world!" << endl;
}

int add(int x, int y) {
  return x + y;
}

int main() {
  int a = 3;
  int b = 4;
  int c = add(a, b); // c will be assigned the value 7
  printMessage();
  return 0;
}
