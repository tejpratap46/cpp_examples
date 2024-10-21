#include <iostream>

int main(int argc, char const *argv[])
{
    void* a = new int(10);

    int b = *(int*) a;

    std::cout << "b: " << b << std::endl;

    return 0;
}
