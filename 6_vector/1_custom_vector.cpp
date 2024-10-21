#include <iostream>

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
            // delete &_data[i];
        }
        delete[] _data;
        _data = new_data;
    }
};

int main() {
    MyVector<int> v;
    std::cout << "add fist" << std::endl;
    v.push_back(35);

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "add second" << std::endl;
    v.push_back(30);

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "add third" << std::endl;
    v.push_back(25);

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "Pop Back" << std::endl;

    v.pop_back();

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }

    std::cout << "add Fourth" << std::endl;
    v.push_back(20);

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "value: " << v[i] << ", address: " << &v[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
