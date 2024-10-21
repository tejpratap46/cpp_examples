#include <iostream>
#include <thread>
#include <chrono>

void getResult(int* result) {
    std::this_thread::sleep_for(std::chrono::seconds(2));

    *result = 100;
}

int main(int argc, char const *argv[])
{
    int* result = new int(10);

    std::thread t1(getResult, result);
    t1.join();

    std::cout << "Result: " << *result << std::endl;

    return 0;
}
