#include <iostream>

class MyArray {
public:
    int arr[10];

    // Overloading [] operator
    int& operator[](int index) {
        return arr[index];
    }
};

int main() {
    MyArray myArray;
    myArray[3] = 5; // Using overloaded []
    std::cout << myArray[3] << std::endl;
    return 0;
}