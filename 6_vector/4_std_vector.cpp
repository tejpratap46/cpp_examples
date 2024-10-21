#include <iostream>
#include <vector>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called for " << name << std::endl;
    }

    // Move constructor
    Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move constructor called for " << name << std::endl;
    }

    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main() {
    std::cout << "Creating initial vector:" << std::endl;
    std::vector<Person> people;
    
    std::cout << "\nAdding people to vector:" << std::endl;
    people.push_back(Person("Jhon", 35));
    people.emplace_back("Alice", 30);
    people.emplace_back("Bob", 25);
    
    std::cout << "\nVector size: " << people.size() << std::endl;
    
    std::cout << "\nCreating a copy of the vector:" << std::endl;
    std::vector<Person> people_copy = people;
    
    std::cout << "\nIntroducing people from original vector:" << std::endl;
    for (const auto& person : people) {
        person.introduce();
    }
    
    std::cout << "\nIntroducing people from copied vector:" << std::endl;
    for (const auto& person : people_copy) {
        person.introduce();
    }
    
    std::cout << "\nAdding a new person to original vector:" << std::endl;
    people.emplace_back("Charlie", 35);
    
    std::cout << "\nOriginal vector size: " << people.size() << std::endl;
    std::cout << "Copied vector size: " << people_copy.size() << std::endl;

    return 0;
}