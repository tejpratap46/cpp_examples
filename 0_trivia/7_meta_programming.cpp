#include <iostream>

// Template metaprogramming for factorial calculation
template<unsigned int N>
struct Factorial {
    static constexpr unsigned int value = N * Factorial<N - 1>::value;
};

// Base case for the recursion
template<>
struct Factorial<0> {
    static constexpr unsigned int value = 1;
};

int main() {
    // Calculate factorials at compile time
    constexpr unsigned int fact5 = Factorial<5>::value;
    constexpr unsigned int fact10 = Factorial<10>::value;

    std::cout << "5! = " << fact5 << std::endl;
    std::cout << "10! = " << fact10 << std::endl;

    return 0;
}