#include <iostream>

class MyClass {
public:
    int data;

    // Overloaded new operator
    void* operator new(size_t size) {
        std::cout << "Overloaded new operator called\n";
        // You can customize memory allocation here
        void* ptr = malloc(size);
        return ptr;
    }

    // Overloaded delete operator
    void operator delete(void* ptr) {
        std::cout << "Overloaded delete operator called\n";
        // You can perform custom deallocation here
        free(ptr);
    }
};

int main() {
    MyClass* obj = new MyClass();

    obj->data = 10;

    std::cout << "value: " << obj->data << std::endl;

    delete obj;
    return 0;
}