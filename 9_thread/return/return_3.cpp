#include <iostream>
#include <thread>
#include <future>

int compute_value(int x) {
    return x * 2;
}

int main() {
    std::packaged_task<int(int)> task(compute_value);
    std::future<int> future = task.get_future();

    std::thread t(std::move(task), 21);

    std::cout << "Waiting for result..." << std::endl;
    std::cout << "Result: " << future.get() << std::endl;

    t.join();
    return 0;
}