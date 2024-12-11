#include <iostream>
using namespace std;

// Base class
class Student {
protected:
    string name;
    int rollNumber;
public:
    void setDetails(string n, int r) {
        name = n;
        rollNumber = r;
    }
    
    void displayDetails() {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << endl;
    }
};

// Derived class
class Person : public Student {
private:
    int age;
public:
    void setAge(int a) {
        age = a;
    }
    
    void displayPersonDetails() {
        displayDetails(); // Inherited from Student
        cout << "Age: " << age << endl;
    }
};

int main() {
    Person p;
    p.setDetails("John Doe", 101);
    p.setAge(20);
    p.displayPersonDetails(); // Shows inherited and additional information

    return 0;
}
