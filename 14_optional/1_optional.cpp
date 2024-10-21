#include <iostream>
#include <optional>

int main() {
    std::optional<int> maybe_number;

    if (maybe_number.has_value()) {
        std::cout << "There's a number!" << std::endl;
    } else {
        std::cout << "No number yet." << std::endl;
    }

    maybe_number = 42;

    if (maybe_number) {
        std::cout << "The number is: " << *maybe_number << std::endl;
    }

    return 0;
}