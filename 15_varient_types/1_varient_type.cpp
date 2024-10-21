#include <iostream>
#include <variant>

int main(int argc, char const *argv[])
{
    std::variant<int, float, std::string> v1 = 5;

    if (auto value = std::get_if<int>(&v1)) {
        std::cout << *value << std::endl;
    }

    v1 = 10.0f;
    v1 = "Test String";

    if (auto value = std::get_if<std::string>(&v1)) {
        std::cout << *value << std::endl;
    }

    return 0;
}
