#include <iostream>
#include <string>

// A simple class to be wrapped
class Person {
public:
    std::string name;
    int age;

    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

// Our wrapper class
class PersonWrapper {
private:
    Person* ptr;

public:
    PersonWrapper(Person* p) : ptr(p) {}

    // Overloaded member access operator
    Person* operator->() {
        std::cout << "Accessing member of Person object" << std::endl;
        return ptr;
    }
};

int main() {
    Person p{"Alice", 30};
    PersonWrapper wrapped(&p);

    // Using the wrapper to access Person members
    wrapped->name = "Bob";
    wrapped->age = 25;
    wrapped->introduce();

    return 0;
}