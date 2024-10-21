#include <memory>
#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destructed\n"; }
};

int main() {
    {
        std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
        {
            std::shared_ptr<MyClass> ptr2 = ptr1; // Share ownership
            std::cout << "Count: " << ptr1.use_count() << std::endl; // Prints 2
        }
        std::cout << "Count: " << ptr1.use_count() << std::endl; // Prints 1
    }
    // MyClass object is automatically deleted here
    return 0;
}