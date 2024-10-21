#include <iostream>

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    operator double() {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    Fraction f(3, 4);
    double value = f; // Implicit conversion to double
    std::cout << value << std::endl;

    return 0;
}