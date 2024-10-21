#include <iostream>

struct Vector1
{
    int a, b;
};

struct Vector2
{
    union
    {
        struct
        {
            int a, b, c, d;
        };
        struct
        {
            Vector1 x, y;
        };
    };
};

struct Vector3
{
    union U1
    {
        struct A1
        {
            int a, b, c, d;
        };
        struct A2
        {
            int x, y, z;
        };
    };
};

void printVector1(Vector1 &v1)
{
    std::cout << v1.a << ", " << v1.b << std::endl;
}

int main(int argc, char const *argv[])
{
    Vector2 v = {1, 2, 3, 4};
    printVector1(v.x);
    printVector1(v.y);

    v.d = 500;
    printVector1(v.x);
    printVector1(v.y);

    Vector3::U1::A1 v3 = {1,2,3,4};

    std::cout << v3.a << std::endl;

    return 0;
}
