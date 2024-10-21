#include <iostream>

using namespace std;

void printData(int a, int b) {
    cout << a << " + " << b << " = " << (a + b) << endl;
}

int main(int argc, char const *argv[])
{   
    int i = 0;
    printData(i++, ++i);
    return 0;
}

// 1+2 = 3
// 0+0 = 0
// 0+1 = 1
// 1+0 = 1