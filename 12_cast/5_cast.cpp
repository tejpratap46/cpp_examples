#include <iostream>

void modify(const int* p) {
    int* nonConstPtr = const_cast<int*>(p);
    *nonConstPtr = 20; // Modifying const data is generally unsafe
}

int main() {
    const int x = 10;
    modify(&x);
    std::cout << x << std::endl; // Output might be undefined

    return 0;
}