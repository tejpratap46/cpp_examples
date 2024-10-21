#include <iostream>

void printName(std::string& name) {
    std::cout << "lvalue: " << name << std::endl;
}

void printName(std::string&& name) {
    std::cout << "rvalue: " << name << std::endl;
}

int main(int argc, char const *argv[])
{
    
    std::string first = "Tej";
    std::string last = "Singh";

    int a = 1 > 3 ? 2 : 4;

    std::string fullName = first + last;

    printName(fullName);
    printName(first + last);

    return 0;
}
