#include <iostream>
#include <functional>

std::function<int(int)> createMultiplier(int factor) {
    return [factor](int x) {
        return x * factor;
    };
}

int main() {
    auto times2 = createMultiplier(2);
    auto times5 = createMultiplier(5);
    
    std::cout << "10 * 2 = " << times2(10) << std::endl;
    std::cout << "10 * 5 = " << times5(10) << std::endl;
    
    return 0;
}