#include <iostream>

class Complex {
public:
    double real, imag;
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

std::ostream& operator<<(std::ostream& os, Complex& com) {
    os << com.imag;
    return os;
}

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2; // Using overloaded +
    std::cout << c3 << "a" << std::endl;
    return 0;
}