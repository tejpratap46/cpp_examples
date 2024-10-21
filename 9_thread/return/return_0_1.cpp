#include <iostream>
#include <thread>

void workerThread(int& result) {
    result = 42; // Assign data to referenced variable
}

int main() {
    int result;
    std::thread t(workerThread, std::ref(result));
    t.join();

    std::cout << "Result from thread: " << result << std::endl;

    return 0;
}