#include <iostream>

// Sample class definition
class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor called" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor called" << std::endl;
    }

    void printMessage() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // Object allocated on the stack
    MyClass obj1;
    
    // Object scope limited to main function
    obj1.printMessage();

    // No need to manually deallocate stack-allocated objects
    return 0;
}