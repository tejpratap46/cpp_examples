#include <iostream>

class MyClass {
public:
    int value;

    MyClass(int v) : value(v) {}

    MyClass& operator,(const MyClass& other) {
        // Custom logic here
        value += other.value;
        return *this;
    }
};

int main() {
    MyClass obj1(5), obj2(3);
    obj1, obj2; // Overloaded comma operator
    std::cout << obj1.value << std::endl; // Output: 8
    return 0;
}