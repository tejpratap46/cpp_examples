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
void* operator new[](size_t size) {
    return operator new(size);
}

// For array deallocations
void operator delete[](void* ptr, size_t size) noexcept {
    operator delete(ptr, size);
}

void printString(const std::string& s) {
    std::cout << s << std::endl;
}

void printString(const std::string_view& s) {
    std::cout << s << std::endl;
}

// Example usage
int main()
{
    std::string b = std::string(32, 'i');
    std::cout << "b address: " << &b << std::endl;
    memTracker.printStats();

    // printString("Test Test Test Test Test Test Test");
    printString(std::string_view(b.c_str(), 16));
    memTracker.printStats();

    return 0;
}