#include <iostream>

class Person {
public:
    int age;
    Person(int a) : age(a) {}

    // Overloading < operator
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

int main() {
    Person p1(25), p2(30);
    if (p1 < p2) {
        std::cout << "p1 is younger than p2" << std::endl;
    }
    return 0;
}