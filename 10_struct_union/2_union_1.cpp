#include <iostream>

union U
{
    int a;
    double b;
};

void printMem(void *location)
{
    unsigned char const *pos = (unsigned char const *)location;

    for (int i = 0; i < 20; i++)
        printf("|%2.2x| ", pos[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    U u1;

    u1.a = 3;
    std::cout << "a: " << u1.a << ", b: " << u1.b << ", size: " << sizeof(u1) << std::endl;
    std::cout << "a: " << &u1.a << ", b: " << &u1.b << ", size: " << sizeof(u1) << std::endl;
    printMem(&u1);
    
    u1.b = 50;
    std::cout << "a: " << u1.a << ", b: " << u1.b << ", size: " << sizeof(u1) << std::endl;
    std::cout << "a: " << &u1.a << ", b: " << &u1.b << ", size: " << sizeof(u1) << std::endl;
    printMem(&u1);

    return 0;
}

