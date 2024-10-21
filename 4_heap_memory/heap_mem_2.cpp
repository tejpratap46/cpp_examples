// scoped pointers
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

class ScopedPtr {
private:
    MyClass* m_Ptr;
  
public:
    ScopedPtr(MyClass* ptr): m_Ptr(ptr) {}

    ScopedPtr(ScopedPtr& other);

    ~ScopedPtr() {
        delete m_Ptr;
    }

    void printMessage() {
        m_Ptr->printMessage();
    }
};

int main() {
    // Object allocated on the heap
    ScopedPtr myClass(new MyClass());
    ScopedPtr myClass2 = myClass;
    
    // Object lifetime managed manually; need to delete when done
    myClass.printMessage();
    
    // distructor will be called autometically
    return 0;
}