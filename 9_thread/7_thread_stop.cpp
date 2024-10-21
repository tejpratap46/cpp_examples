#include <iostream>
#include <thread>
#include <chrono>

bool shouldRun = true;

void threadTask() {
    while (shouldRun)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Running" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(threadTask);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    // t1.detach();
    shouldRun = false;
    t1.join();
    return 0;
}
