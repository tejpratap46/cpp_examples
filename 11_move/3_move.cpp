#include <iostream>
#include <string.h>

class String
{
private:
    int p_length = 0;
    char *p_str = nullptr;

public:
    String() = default;

    // main
    String(const char* data)
    {
        std::cout << "Created:" << std::endl;
        p_length = strlen(data);
        p_str = new char[p_length];
        memcpy(p_str, data, p_length);
    }

    // copy
    String(const String& other)
    {
        std::cout << "Created:" << std::endl;
        p_length = other.p_length;
        p_str = new char[p_length];
        memcpy(p_str, other.p_str, p_length);
    }
    
    String& operator=(const String& other)
    {
        std::cout << "Operator Created:" << std::endl;
        p_length = other.p_length;
        p_str = new char[p_length];
        memcpy(p_str, other.p_str, p_length);

        return *this;
    }

    // move
    String(String&& other)
    {
        std::cout << "Moved:" << std::endl;
        p_length = other.p_length;
        p_str = other.p_str;

        other.p_length = 0;
        other.p_str = nullptr;
    }

    // move
    String &operator=(String &&other)
    {
        if (this != &other)
        {

            std::cout << "Operator Moved:" << std::endl;
            delete[] p_str;

            p_length = other.p_length;
            p_str = other.p_str;

            other.p_length = 0;
            other.p_str = nullptr;
        }

        return *this;
    }

    // dest
    ~String()
    {
        std::cout << "Distructor: " << std::endl;
        delete p_str;
    }

    void print() {
        for (size_t i = 0; i < p_length; i++)
        {
            std::cout << p_str[i];
        }
        
    }
};

int main(int argc, char const *argv[])
{
    String a = "A";
    String b;
    b = a;

    return 0;
}
