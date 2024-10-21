#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex cout_mutex;

void detachedThreadFunction(int id) {
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // Use a mutex to ensure thread-safe console output
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Detached thread " << id << " finished its work." << std::endl;
}

int main() {
    std::cout << "Main thread starting..." << std::endl;

    // Create and detach three threads
    for (int i = 1; i <= 3; ++i) {
        std::thread t(detachedThreadFunction, i);
        t.detach();
        std::cout << "Thread " << i << " detached." << std::endl;
    }

    // Main thread continues its work
    std::cout << "Main thread continues working..." << std::endl;

    // Sleep to allow detached threads time to complete
    // (In a real scenario, the main thread would do actual work here)
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "Main thread finished." << std::endl;

    return 0;
}