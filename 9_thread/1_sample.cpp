#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>

// 1. Thread creation and 2. Thread functions
void simple_thread_function() {
    std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
}

// 3. Joining threads
void join_example() {
    std::thread t(simple_thread_function);
    t.join(); // Wait for thread to finish
}

// 4. Detaching threads
void detach_example() {
    std::thread t([]() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Detached thread finished" << std::endl;
    });
    t.detach(); // Allow thread to run independently
}

// 5. Mutex (Mutual Exclusion)
std::mutex mtx;
int shared_variable = 0;

void mutex_example() {
    mtx.lock();
    shared_variable++;
    mtx.unlock();
}

// 6. Lock guards
void lock_guard_example() {
    std::lock_guard<std::mutex> lock(mtx);
    shared_variable++; // Automatically unlocks when lock goes out of scope
}

// 7. Condition variables
std::condition_variable cv;
bool ready = false;

void wait_for_signal() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    std::cout << "Signal received" << std::endl;
}

void send_signal() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}

// 8. Atomic operations
std::atomic<int> atomic_counter(0);

void atomic_example() {
    atomic_counter++; // Thread-safe increment
}

int main() {
    // 1 & 2. Thread creation and functions
    std::thread t1(simple_thread_function);
    t1.join();

    // 3. Joining threads
    join_example();

    // 4. Detaching threads
    detach_example();

    auto lambda = []() {
        std::cout << "lambda thread" << std::endl;
    };

    std::thread lambdaThread = std::thread(lambda);
    lambdaThread.join();

    std::this_thread::sleep_for(std::chrono::seconds(3)); // Wait for detached thread

    // 5 & 6. Mutex and lock guards
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(lock_guard_example);
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "Shared variable: " << shared_variable << std::endl;

    // 7. Condition variables
    std::thread waiter(wait_for_signal);
    std::thread signaler(send_signal);
    waiter.join();
    signaler.join();

    // 8. Atomic operations
    std::vector<std::thread> atomic_threads;
    for (int i = 0; i < 1000; ++i) {
        atomic_threads.emplace_back(atomic_example);
    }
    for (auto& t : atomic_threads) {
        t.join();
    }
    std::cout << "Atomic counter: " << atomic_counter << std::endl;

    return 0;
}