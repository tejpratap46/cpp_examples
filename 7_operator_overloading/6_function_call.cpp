#include <iostream>

class Callable {
public:
    void operator()(int x) {
        std::cout << "Called with: " << x << std::endl;
    }
};

int main() {
    Callable obj;
    obj(10); // Using overloaded ()
    return 0;
}