#include <iostream>
#include <tuple>

std::tuple<std::string, int, float> getValue() {
    return {"Tej", 31, 5.8f};
}

int main(int argc, char const *argv[])
{
    std::string name;
    int age;
    float height;
    std::tie(name, age, height) = getValue();

    std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;

    return 0;
}
