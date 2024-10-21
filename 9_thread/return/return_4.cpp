#include <future>
#include <thread>
#include <iostream>

int compute_value() {
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t([&promise]() {
        promise.set_value(compute_value());
    });

    std::cout << "Waiting for result..." << std::endl;
    std::cout << "Result: " << future.get() << std::endl;

    t.join();
    return 0;
}