#include <iostream>

int main() {
    double x = 3.14;
    int y = static_cast<int>(x); // Explicit conversion from double to int

    std::cout << y << std::endl; // Output: 3

    return 0;
}