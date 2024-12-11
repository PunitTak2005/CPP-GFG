
#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    // Constructor
    Counter(int v = 0) : value(v) {}

    // Overload unary ++ (prefix)
    Counter& operator++() {
        ++value;  // Increment value
        return *this; // Return the updated object
    }

    // Overload binary ++ (simulated as addition with another Counter)
    Counter operator++(int) {
        Counter temp = *this; // Store the current state
        value++;              // Increment value
        return temp;          // Return the original state
    }

    // Display function
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c1(5);

    cout << "Original value:" << endl;
    c1.display();

    // Unary ++ (prefix)
    ++c1;
    cout << "After prefix ++:" << endl;
    c1.display();

    // Binary ++ (postfix)
    c1++;
    cout << "After postfix ++:" << endl;
    c1.display();

    return 0;
}
