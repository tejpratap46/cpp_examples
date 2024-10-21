#include <iostream>
#include <string>

class MyClass {
public:
    int size;

    MyClass(const int size) : size(size) {}

    // Conversion operator to string
    operator std::string() const {
        return std::to_string(size);
    }
};

int main() {
    MyClass obj(5);

    // Using the conversion operator to get a string
    std::string str = obj;

    std::cout << str << std::endl; // Output: Hello
}