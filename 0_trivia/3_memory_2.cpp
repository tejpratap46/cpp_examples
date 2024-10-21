#include <iostream>
#include <string.h>
#include <map>
#include <vector>

// Global map to track memory allocations
std::map<std::string, std::vector<void*>> memory_tracker;

// Overloaded new operator for strings
void* operator new(size_t size, const char* type_name) {
    void* ptr = ::new char[size];

    if (ptr && std::string(type_name) == "char[]") {
        memory_tracker[std::string(type_name)].push_back(ptr);
    }

    return ptr;
}

// Overloaded delete operator for strings
void operator delete(void* ptr, const char* type_name) {
    if (ptr && std::string(type_name) == "char[]") {
        for (auto it = memory_tracker[std::string(type_name)].begin(); it != memory_tracker[std::string(type_name)].end();) {
            if (*it == ptr) {
                it = memory_tracker[std::string(type_name)].erase(it);
                ::delete[] reinterpret_cast<char*>(ptr);
                break;
            } else {
                ++it;
            }
        }
    } else {
        ::delete[] reinterpret_cast<char*>(ptr);
    }
}

// Function to print memory allocation statistics
void print_statistics() {
    std::cout << "Memory Allocation Statistics:" << std::endl;
    for (const auto& entry : memory_tracker) {
        std::cout << "Type: " << entry.first << std::endl;
        std::cout << "Allocations: " << entry.second.size() << std::endl;
        for (void* ptr : entry.second) {
            std::cout << " - Pointer: 0x" << std::hex << reinterpret_cast<size_t>(ptr) << std::dec << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Allocate memory using the overloaded new operator
    char* ptr1 = new char[str1.length() + 1];
    char* ptr2 = new char[str2.length() + 1];
    char* ptr3 = new char[str1.length() + 1];

    // Copy the strings
    strcpy(ptr1, str1.c_str());
    strcpy(ptr2, str2.c_str());
    strcpy(ptr3, str1.c_str());

    // Deallocate memory using the overloaded delete operator
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;

    print_statistics();

    return 0;
}