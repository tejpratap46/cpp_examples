#include <iostream>
#include <string.h>

class String
{
private:
    int p_length;
    char *p_str;

public:

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

    // move
    String(String&& other)
    {
        std::cout << "Moved:" << std::endl;
        p_length = other.p_length;
        p_str = other.p_str;

        other.p_length = 0;
        other.p_str = nullptr;
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

class Holder
{
private:
    String p_data;

public:
    Holder(const String& str) : p_data(str) {}

    Holder(const String&& str) : p_data((String&&) str) {}

    void printData() {
        p_data.print();
    }
};

int main(int argc, char const *argv[])
{
    Holder holder("Tej Pratap");
    holder.printData();

    std::cin.get();

    return 0;
}
