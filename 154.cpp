#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a triangle" << endl;
    }
};

int main() {
    Shape* shape;
    
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
    
    shape = &circle;
    shape->draw();  // Output: Drawing a circle
    
    shape = &rectangle;
    shape->draw();  // Output: Drawing a rectangle
    
    shape = &triangle;
    shape->draw();  // Output: Drawing a triangle
    
    return 0;
}
