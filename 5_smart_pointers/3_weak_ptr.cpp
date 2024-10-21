#include <iostream>
#include <memory>

class Person {
public:
    Person(const std::string& name) : name_(name) {
        std::cout << name_ << " created" << std::endl;
    }
    ~Person() {
        std::cout << name_ << " destroyed" << std::endl;
    }
    void greet() {
        std::cout << "Hello, I'm " << name_ << std::endl;
    }

private:
    std::string name_;
};

int main() {
    // Create a shared pointer
    std::shared_ptr<Person> shared = std::make_shared<Person>("Alice");
    
    // Create a weak pointer from the shared pointer
    std::weak_ptr<Person> weak = shared;
    
    // Use the weak pointer
    if (auto temp = weak.lock()) {
        temp->greet();
    } else {
        std::cout << "Object no longer exists" << std::endl;
    }
    
    // Reset the shared pointer
    shared.reset();
    
    // Try to use the weak pointer again
    if (auto temp = weak.lock()) {
        temp->greet();
    } else {
        std::cout << "Object no longer exists" << std::endl;
    }
    
    return 0;
}