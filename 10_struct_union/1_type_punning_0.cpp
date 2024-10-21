#include <iostream>

int main(int argc, char const *argv[])
{
    int a = 2;
    std::cout << "a: " << a << ", address: " << &a << std::endl;
    
    double b = a;
    std::cout << "b: " << b << ", address: " << &b << std::endl;

    return 0;
}
