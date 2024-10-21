#include <iostream>
#include <thread>

int a = 0;

void threadFun(int i) {
    ++a;
    std::cout << "id: " << i << "a = " << a << std::endl;
}

int main(int argc, char const *argv[])
{
    
    std::thread t1 = std::thread(threadFun, 1);
    std::thread t2 = std::thread(threadFun, 2);
    std::thread t3 = std::thread(threadFun, 3);
    std::thread t4 = std::thread(threadFun, 4);

    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    /* code */
    return 0;
}
