#include <iostream>

class MyClass {
public:
    int a;
    int b;

    MyClass(int x, int y) : a(x), b(y) {}

    // Function to swap the values using pointers
    void swap(MyClass* obj) {
        int temp = this->a;
        this->a = obj->a;
        obj->a = temp;

        temp = this->b;
        this->b = obj->b;
        obj->b = temp;
    }

    void print() {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};

int main() {
    MyClass obj1(10, 20);
    MyClass obj2(30, 40);

    std::cout << "Before swap:" << std::endl;
    obj1.print();
    obj2.print();

    obj1.swap(&obj2);

    std::cout << "After swap:" << std::endl;
    obj1.print();
    obj2.print();

    return 0;
}
