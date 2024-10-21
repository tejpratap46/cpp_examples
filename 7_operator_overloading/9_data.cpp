#include <iostream>
#include <string.h>

class String
{
private:
    char* p_data = nullptr;
public:
    String() = default;
    String(const char* data) {
        int length = strlen(data);
        p_data = new char[length];
        memcpy(p_data, data, length);
    }

    friend std::ostream& operator<<(std::ostream& os, String& str);

    operator bool() {
        return p_data != nullptr
        && strlen(p_data) > 0;
    }
};

std::ostream& operator<<(std::ostream& os, String& str) {
    os << str.p_data;
    return os;
}

int main(int argc, char const *argv[])
{
    /* code */
    String s = "ASD";
    if (s) {
        std::cout << s << std::endl;
    }

    return 0;
}
