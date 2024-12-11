#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int rollNo;
    void setDetails(string n, int r) {
        name = n;
        rollNo = r;
    }
    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};
int main() {
    Student students[3];
    students[0].setDetails("Alice", 101);
    students[1].setDetails("Bob", 102);
    students[2].setDetails("Charlie", 103);
    for (int i = 0; i < 3; i++) {
        students[i].display();
    }
    return 0;
}
