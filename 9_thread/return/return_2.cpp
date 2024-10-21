#include <future>
#include <thread>
#include <iostream>

int compute_value() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    std::future<int> future = std::async(std::launch::async, compute_value);

    std::cout << "Waiting for result..." << std::endl;
    std::cout << "Result: " << future.get() << std::endl;

    return 0;
}