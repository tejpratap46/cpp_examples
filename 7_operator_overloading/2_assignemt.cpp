#include <iostream>
#include <cstring>

class StringWrapper {
private:
    char* str;

public:
    // Constructor
    StringWrapper(const char* s = nullptr) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] str;
    }

    // Copy constructor
    StringWrapper(const StringWrapper& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Assignment operator overloading
    // StringWrapper& operator=(const StringWrapper& other) {
    //     if (this != &other) {  // Self-assignment check
    //         // Free the existing resource
    //         delete[] str;

    //         // Allocate new resource and copy
    //         str = new char[strlen(other.str) + 1];
    //         strcpy(str, other.str);
    //     }
    //     return *this;
    // }

    // Method to get the string
    const char* getString() const {
        return str;
    }
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2("World");
    StringWrapper s3 = s1;  // Copy constructor

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;

    s2 = s1;  // Assignment operator

    std::cout << "After s2 = s1:" << std::endl;
    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;

    return 0;
}