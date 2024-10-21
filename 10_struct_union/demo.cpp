#include <iostream>

void printMem(void *location)
{
    unsigned char const *pos = (unsigned char const *)location;

    for (int i = 0; i < 20; i++)
        printf("|%2.2x| ", pos[i]);
    printf("\n");
}

struct demo
{
    int a, b;
};

struct demo2
{
    union
    {
        struct
        {
            int a, b, c, d;
        };
        struct
        {
            demo x, y;
        };
    };
};

void printDemo(demo& d) {
    std::cout << d.a << ", " << d.b << std::endl;
}

int main(int argc, char const *argv[])
{
    demo2 a = {1, 2, 3, 4};
    printDemo(a.x); // 1, 2
    printDemo(a.y); // 3, 4

    printDemo(a.x); // 1, 2
    printDemo(a.y); // 3, 100

    printMem(&a);
    return 0;
}
