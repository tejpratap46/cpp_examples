#include <iostream>

struct Vector
{
    int a, b;
};

void printMem(void *location)
{
    unsigned char const *pos = (unsigned char const *)location;

    for (int i = 0; i < 20; i++) {
        printf("|%2.2x| ", pos[i]);
    }
    
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Vector v = {1 ,2};
    printMem(&v);

    int* v2 = (int*) &v;
    std::cout << "a: " << v2[0] << ", b: " << v2[1] << std::endl;

    return 0;
}

