#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

class MyInt {
private:
    int _int;

public:
    MyInt() : _int(0) {
        std::cout << "Default Constructor called for " << _int << ", address: " << &_int << std::endl;
    }

    MyInt(int a) : _int(a) {
        std::cout << "Constructor called for " << _int << ", address: " << &_int << std::endl;
    }

    ~MyInt() {
        std::cout << "Deconstructor called for " << _int << ", address: " << &_int << std::endl;
    }

    // Copy constructor
    MyInt(const MyInt& other): _int(other._int) {
        std::cout << "Copy constructor called for " << _int << ", address: " << &_int << std::endl;
    }

    // Move constructor
    MyInt(MyInt&& other) noexcept : _int(other._int) {
        std::cout << "Move constructor called for " << _int << ", address: " << &_int << std::endl;
    }

    void introduce() const {
        std::cout << "MyInt Value:  " << _int << ", address: " << &_int << std::endl;
    }

    MyInt& operator=(const MyInt& other) {
        if (this != &other) {
            _int = other._int;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyInt& obj);
};

std::ostream& operator<<(std::ostream& os, const MyInt& obj) {
    os << "value: " << obj._int;
    return os;
}

template<typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void realloc(size_t newCapacity) {
        T* newData = static_cast<T*>(malloc(newCapacity * sizeof(T)));
        if (newData == nullptr) {
            throw std::bad_alloc();
        }
        
        if (data != nullptr) {
            memcpy(newData, data, size * sizeof(T));
            free(data);
        }
        
        data = newData;
        capacity = newCapacity;
    }

public:
    CustomVector() : data(nullptr), size(0), capacity(0) {}

    ~CustomVector() {
        clear();
        if (data != nullptr) {
            free(data);
        }
    }

    void push_back(const T& value) {
        if (size == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            realloc(newCapacity);
        }
        memcpy(data + size, &value, sizeof(T));
        ++size;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    void clear() {
        size = 0;
    }

    // Custom iterator implementation
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}
        T& operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

// Example usage
int main() {
    CustomVector<MyInt> v;
    std::cout << "add fist" << std::endl;
    v.push_back(MyInt(35));
    
    for (size_t i = 0; i < v.get_size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add second" << std::endl;
    v.push_back(MyInt(30));
    
    for (size_t i = 0; i < v.get_size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add third" << std::endl;
    v.push_back(MyInt(25));

    for (size_t i = 0; i < v.get_size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "pop back" << std::endl;
    v.pop_back();

    for (size_t i = 0; i < v.get_size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add fourth" << std::endl;
    v.push_back(MyInt(20));

    for (size_t i = 0; i < v.get_size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    return 0;
}