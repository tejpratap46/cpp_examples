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
    // Object allocated on the heap
    MyClass *ptr = new MyClass();
    
    // Object lifetime managed manually; need to delete when done
    ptr->printMessage();

    // Explicitly deallocate heap-allocated object to avoid memory leak
    // delete ptr;

    return 0;
}