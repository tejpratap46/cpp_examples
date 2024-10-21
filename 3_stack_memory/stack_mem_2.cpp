#include <iostream>

int* createArray(int size)
{
    static int arr[5];

    return arr;
}

int main()
{
    int size = 3;
    // Object allocated on the stack
    int* array = createArray(size);

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}