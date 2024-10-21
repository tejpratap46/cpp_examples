#include <iostream>

int main() {
    int x = 10;
    double y = (double) x; // Implicit conversion from int to double

    std::cout << y << std::endl; // Output: 10.0

    return 0;
}