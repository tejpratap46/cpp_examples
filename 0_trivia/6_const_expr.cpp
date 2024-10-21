#include <iostream>

constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(1000); // Evaluated at compile time
    std::cout << result << std::endl; // Output: 25
}