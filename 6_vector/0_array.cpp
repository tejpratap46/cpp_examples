#include <iostream>
#include <array>

#define SIZE 2

int main(int argc, char const *argv[])
{
    int array[SIZE] = {1, 2};

    std::cout << "array: " << array << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << "value: " << array[i] << ", address: " << &array[i] << std::endl;
    }

    // uncomment below, see what happens
    // array[2] = 3;

    return 0;
}
