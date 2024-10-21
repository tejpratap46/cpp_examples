#include <iostream>

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
    MyInt(MyInt&& other) noexcept : _int(std::move(other._int)) {
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

template <typename T>
class MyVector {
public:
    MyVector() : _data(nullptr), _size(0), capacity(0) {}

    ~MyVector() {
        delete[] _data;
    }

    void push_back(const T& value) {
        if (_size == capacity) {
            resize();
        }
        _data[_size++] = value;
    }

    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    size_t size() const {
        return _size;
    }

private:
    T* _data;
    size_t _size;
    size_t capacity;

    void resize() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
    }
};

int main() {
    MyVector<MyInt> v;
    std::cout << "add fist" << std::endl;
    v.push_back(MyInt(35));
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add second" << std::endl;
    v.push_back(MyInt(30));
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add third" << std::endl;
    v.push_back(MyInt(25));

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "pop back" << std::endl;
    v.pop_back();

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    
    std::cout << "add fourth" << std::endl;
    v.push_back(MyInt(20));

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    return 0;
}
