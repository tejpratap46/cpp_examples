#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void threadFunction(int id) {
    std::cout << "Thread " << id << " starting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " finished." << std::endl;
}

class ThreadManager {
private:
    std::vector<std::thread> threads;

public:
    void addThread(std::thread&& t) {
        threads.push_back(std::move(t));
    }

    void joinAll() {
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    }
};

int main() {
    ThreadManager manager;

    std::cout << "Main function starting..." << std::endl;

    {
        std::thread t1(threadFunction, 1);
        manager.addThread(std::move(t1));

        std::cout << "Created and moved thread 1" << std::endl;
    }

    {
        std::thread t2(threadFunction, 2);
        manager.addThread(std::move(t2));

        std::cout << "Created and moved thread 2" << std::endl;
    }

    std::cout << "Both thread objects have gone out of original scope" << std::endl;
    std::cout << "Main thread continues..." << std::endl;

    manager.joinAll();

    std::cout << "All threads have completed. Main function ending." << std::endl;

    return 0;
}