#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

public:
    // Constructor
    String(const char* str = nullptr) {
        if (str == nullptr) {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        } else {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
    }

    
    // String(const String& other) {
    //     length = other.length;
    //     data = other.data;
    // }

    // See what will happen if you remove below Copy constructor
    // Copy constructor
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // For demonstration purposes
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    String s1("Hello");
    String s2 = s1;  // Copy constructor is called

    s1.print();  // Output: Hello
    s2.print();  // Output: Hello

    return 0;
}