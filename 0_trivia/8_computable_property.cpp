#include <iostream>

const int x = []{
    std::cout << "x1" << std::endl;
    int res = 4;
    res *= 10;
    res += 5;
    return res;
}();

int main(int argc, char const *argv[])
{
    std::cout << "x2" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "x3" << std::endl;
    return 0;
}
