#include <iostream>

static int a = 10;
// int& getValue() {
//     return a;
// }

int& getValue() {
    static int c = 40;
    return c;
}

int main(int argc, char const *argv[])
{
    int b = 10;

    getValue() = 30;

    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}
