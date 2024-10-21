#include <iostream>
#include <thread>

int result;

void workerThread() {
    result = 42; // Assign data to global variable
}

int main() {
    std::thread t(workerThread);
    t.join();

    std::cout << "Result from thread: " << result << std::endl;

    return 0;
}