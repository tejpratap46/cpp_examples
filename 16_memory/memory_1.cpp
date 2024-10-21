#include <iostream>
#include <cstdlib>
#include <new>

class SimpleMemoryTracker
{
private:
    size_t totalAllocated;
    size_t totalFreed;
    size_t allocationCount;

public:
    SimpleMemoryTracker() : totalAllocated(0), totalFreed(0), allocationCount(0) {}

    void recordAllocation(size_t size)
    {
        totalAllocated += size;
        allocationCount++;
    }

    void recordDeallocation(size_t size)
    {
        totalFreed += size;
        allocationCount--;
    }

    void printStats()
    {
        std::cout << "\nMemory usage statistics:\n";
        // std::cout << "Total allocated: " << totalAllocated << " bytes\n";
        // std::cout << "Total freed: " << totalFreed << " bytes\n";
        std::cout << "Current usage: " << (totalAllocated - totalFreed) << " bytes\n";
        std::cout << "Number of active allocations: " << allocationCount << "\n\n";
    }
};

SimpleMemoryTracker memTracker;

void *operator new(size_t size)
{
    std::cout << "New allocation " << size << "\n";
    void *ptr = std::malloc(size);
    if (ptr == nullptr)
    {
        throw std::bad_alloc();
    }
    memTracker.recordAllocation(size);
    return ptr;
}

void operator delete(void *ptr, size_t size) noexcept
{

    std::cout << "New deletion " << size << "\n";
    if (ptr != nullptr)
    {
        memTracker.recordDeallocation(size);
        std::free(ptr);
    }
}

// For array allocations
void *operator new[](size_t size)
{
    return operator new(size);
}

// For array deallocations
void operator delete[](void *ptr, size_t size) noexcept
{
    operator delete(ptr, size);
}

void printString(const std::string &str, int start, int end)
{
    for (size_t i = start; i < end; i++)
    {
        std::cout << str.at(i);
    }
    std::cout << std::endl;
}

void print(const std::string_view str) {
    std::cout << str;
}

// Example usage
int main()
{
    // int *a = new int(5);
    // std::cout << "a address: " << a << std::endl;
    // memTracker.printStats();

    // std::string* b = new std::string("Tej");
    // std::cout << "b address: " << &b << std::endl;
    // memTracker.printStats();

    // double *c = new double(10);
    // std::cout << "c address: " << c << std::endl;
    // memTracker.printStats();

    // delete a;
    // std::cout << "delete a" << std::endl;
    // memTracker.printStats();

    // delete b;
    // std::cout << "delete b" << std::endl;
    // memTracker.printStats();

    // delete c;
    // std::cout << "delete c" << std::endl;
    // memTracker.printStats();

    // std::string str = std::string(50, 'q');

    // printString(str, 0, 20);

    char* str = "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";

    print(std::string_view(str, 20));

    memTracker.printStats();
    std::cout << str << std::endl;

    return 0;
}