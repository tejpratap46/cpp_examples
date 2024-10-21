#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destructed\n"; }
};

int main() {
    // Create a shared pointer
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::cout << "Reference count after ptr1 creation: " << ptr1.use_count() << std::endl;

    // Create another shared pointer pointing to the same object
    std::shared_ptr<MyClass> ptr2 = ptr1;
    std::cout << "Reference count after ptr2 creation: " << ptr1.use_count() << std::endl;

    // Create a weak pointer
    std::weak_ptr<MyClass> weak = ptr1;
    std::cout << "Reference count after weak ptr creation: " << ptr1.use_count() << std::endl;

    // Reset ptr2
    ptr2.reset();
    std::cout << "Reference count after ptr2 reset: " << ptr1.use_count() << std::endl;

    // Reset ptr1
    ptr1.reset();
    std::cout << "Reference count after ptr1 reset: " << (weak.expired() ? 0 : weak.lock().use_count()) << std::endl;

    return 0;
}