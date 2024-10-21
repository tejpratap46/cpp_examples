#include <iostream>
#include <string>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Function to perform calculation based on the function pointer
int calculate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

int main() {
    int x = 10, y = 5;
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    std::string opNames[] = {"Addition", "Subtraction", "Multiplication", "Division"};
    
    for (int i = 0; i < 4; ++i) {
        std::cout << opNames[i] << ": " << calculate(x, y, operations[i]) << std::endl;
    }

    return 0;
}

// Function definitions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; } // Simple division by zero check