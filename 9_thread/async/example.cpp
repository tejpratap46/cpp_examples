#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// 1. Create asynchronous tasks using std::async
int compute_sum(int a, int b) {
    std::cout << "thread compute_sum : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    return a + b;
}

void async_example() {
    std::future<int> future_sum = std::async(std::launch::async, compute_sum, 2, 3);
    std::cout << "Async sum: " << future_sum.get() << std::endl;
}

// 2. Use std::future to get results from asynchronous operations
void future_example() {
    auto future_result = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 42;
    });
    
    std::cout << "Future result: " << future_result.get() << std::endl;
}

// 3. Implement promise-future mechanisms with std::promise
void promise_example() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread producer([&promise]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        promise.set_value(100);
    });

    std::cout << "Promise-future result: " << future.get() << std::endl;
    producer.join();
}

// 4. Manage shared states between threads
void shared_state_example() {
    std::promise<void> ready_promise, t1_ready_promise, t2_ready_promise;
    std::shared_future<void> ready_future(ready_promise.get_future());

    std::thread t1([&t1_ready_promise, ready_future]() {
        t1_ready_promise.set_value();
        ready_future.wait(); // Wait until the signal is set by the main thread
        std::cout << "Thread 1 is running" << std::endl;
    });

    std::thread t2([&t2_ready_promise, ready_future]() {
        t2_ready_promise.set_value();
        ready_future.wait(); // Wait until the signal is set by the main thread
        std::cout << "Thread 2 is running" << std::endl;
    });

    t1_ready_promise.get_future().wait();
    t2_ready_promise.get_future().wait();
    ready_promise.set_value();

    t1.join();
    t2.join();
}

// 5. Handle exceptions in asynchronous code
void exception_example() {
    auto future = std::async(std::launch::async, []() {
        throw std::runtime_error("Async error");
    });

    try {
        future.get();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "thread main : " << std::this_thread::get_id() << std::endl;
    
    std::cout << "1. Async example:" << std::endl;
    async_example();

    std::cout << "\n2. Future example:" << std::endl;
    future_example();

    std::cout << "\n3. Promise example:" << std::endl;
    promise_example();

    std::cout << "\n4. Shared state example:" << std::endl;
    shared_state_example();

    std::cout << "\n5. Exception handling example:" << std::endl;
    exception_example();

    return 0;
}