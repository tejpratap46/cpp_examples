#include <iostream>

int main() {
    int x = 10;
    char* p = reinterpret_cast<char*>(&x);

    // Unsafe and generally not recommended
    std::cout << *p << std::endl;

    return 0;
}