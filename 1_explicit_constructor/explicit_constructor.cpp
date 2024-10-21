#include <iostream>
#include <string>

class User {
private:
	std::string name;
	int age;

public:
	// Non-explicit constructor
	User(const std::string &s) :
			name(s), age(0) {
		std::cout << "Char* constructor called" << std::endl;
	}

	// Explicit constructor
	explicit User(int _age) :
	// User(int _age) :
			name("UNKNOWN"), age(_age) {
		std::cout << "Integer constructor called" << std::endl;
	}

	void print() const {
		std::cout << "Name: " << name << std::endl << "Age: " << age
				<< std::endl;
	}
};

void takeMyString(const User &ms) {
	ms.print();
}

int main() {
	User u1("Tej");
    User u2(5);

	std::cout << "user 1: " << &u1 << std::endl;
	return 0;
}
