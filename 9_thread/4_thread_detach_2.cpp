#include <iostream>
#include <thread>
#include <chrono>

void threadFunction() {
    std::cout << "Thread starting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread finished." << std::endl;
}

int main() {
    std::cout << "Main function starting..." << std::endl;

    {
        std::thread t(threadFunction);
        // Neither joining nor detaching the thread
        
        std::cout << "Thread object going out of scope..." << std::endl;
    } // t's destructor is called here

    std::cout << "This line will not be reached." << std::endl;

    return 0;
}