#include <iostream>
#include <string>

class User {
private:
	std::string name;

public:
	// Non-explicit constructor
	User(const std::string &s) :
			name(s) {
		std::cout << "Char* constructor called" << std::endl;
	}

	// Copy Constructor
	User(const User& other) {
		std::cout << "Copy constructor called" << std::endl;
        name = other.name;
    }

	void print() const {
		std::cout << "Name: " << name << std::endl;
	}
};

void takeMyUser(const User &ms) {
	ms.print();
}

int main() {

	User user1("Tej");
	std::cout << "user 1: " << &user1 << std::endl;

	User user2 = user1;
	std::cout << "user 2: " << &user2 << std::endl;

	takeMyUser(user1);

	return 0;
}
