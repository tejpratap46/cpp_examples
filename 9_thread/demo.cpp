#include <iostream>
#include <thread>
#include <climits>
#include <chrono>
#include <ctime>

std::string getTimeStr()
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::cout << s << std::endl;
    return s;
}

long int sum = 0;

void run(int start, int end)
{
    for (size_t i = start; i < end; i++)
    {
        sum += i;
    }

    std::cout << "sum = " << sum << ", ID = " << std::this_thread::get_id() << std::endl;
}

// main > t1[x] > t2 > t100
// main > t3 > t4

void spawnThreads()
{
    std::thread t0 = std::thread(run, 0, INT_MAX);
    std::thread t2 = std::thread(run, 0, INT_MAX);
    std::thread t3 = std::thread(run, 0, INT_MAX);
    std::thread t4 = std::thread(run, 0, INT_MAX);
    std::thread t5 = std::thread(run, 0, INT_MAX);
}

int main(int argc, char const *argv[])
{
    std::cout << "main thread ID = " << std::this_thread::get_id() << std::endl;

    // getTimeStr();
    // run(0, INT_MAX);
    // std::cout << "sum = " << sum << std::endl;
    // getTimeStr();
    // run(0, INT_MAX);
    std::cout << "Threads = " << std::thread::hardware_concurrency() << std::endl;
    // getTimeStr();

    getTimeStr();
    std::thread t0 = std::thread(run, 0, INT_MAX);
    // std::thread t1 = std::thread(run2, 0, INT_MAX);

    std::cout << "joinable: " << t0.joinable() << std::endl;

    t0.detach();

    std::cout << "joinable: " << t0.joinable() << std::endl;
    // t1.join();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    getTimeStr();

    return 0;
}
