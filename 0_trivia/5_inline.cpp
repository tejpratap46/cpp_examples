#include <iostream>

// #define square(x) (x * x)
inline int square(int x) { 
    return x * x;
}

int main(int argc, char const *argv[])
{
    /* code */
    asm("marker1:");
    int sqOf5 = 25;
    asm("marker1:");
    std::cout << sqOf5 << std::endl;
    return 0;
}
