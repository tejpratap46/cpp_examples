#include <iostream>

struct Vector1
{
    int a, b;
};

struct Vector2
{
    int a, b, c, d;

    Vector1* getVector1() {
        return (Vector1*) &a;
    }
};

void printVector1(Vector1& vec1) {
    std::cout << vec1.a << ", " << vec1.b << std::endl;
}

int main(int argc, char const *argv[])
{
    Vector2 v2 = {1,2,3,4};

    printVector1(v2.getVector1()[0]);
    printVector1(v2.getVector1()[1]);

    return 0;
}

