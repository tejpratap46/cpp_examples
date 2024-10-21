#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    std::array<int, 100> array = {1,2,3,4};

    std::array<int, 5> array2 = {};

    for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << "value: " << array[i] << ", address: " << &array[i] << std::endl;
    }
    

    return 0;
}
