#include <iostream>
#include <tuple>

std::tuple<std::string, int, float> getValue() {
    return {"Tej", 31, 5.8f};
}

int main(int argc, char const *argv[])
{
    auto value = getValue();
    std::string& name = std::get<0>(value);
    int age = std::get<1>(value);
    float height = std::get<2>(value);

    std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;

    return 0;
}
