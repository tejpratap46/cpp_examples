#include <iostream>
#include <string.h>

class String
{
private:
    int p_length = 0;
    char *p_data = nullptr;

public:
    String() = default;

    explicit String(const char *o_data)
    {
        std::cout << "Const" << std::endl;

        p_length = strlen(o_data);
        p_data = new char[p_length];
        memcpy(p_data, o_data, p_length);
    }

    String(const String &o_data)
    {
        std::cout << "Copy Const" << std::endl;

        p_length = strlen(o_data.p_data);
        p_data = new char[p_length];
        memcpy(p_data, o_data.p_data, p_length);
    }

    String(String &&o_data)
    {
        std::cout << "Move Const" << std::endl;

        p_length = o_data.p_length;
        p_data = o_data.p_data;

        o_data.p_length = 0;
        o_data.p_data = nullptr;
    }

    String &operator=(String &&o_data)
    {
        // if (this != &o_data)
        // {
            delete[] p_data;

            std::cout << "Move = Const" << std::endl;

            p_length = o_data.p_length;
            p_data = o_data.p_data;

            o_data.p_length = 0;
            o_data.p_data = nullptr;
        // }

        return *this;
    }

    ~String()
    {
        std::cout << "Dist" << std::endl;
        delete p_data;
    }

    void print()
    {
        for (size_t i = 0; i < p_length; i++)
        {
            std::cout << p_data[i];
        }
        std::cout << std::endl;
    }
};

void print(String p)
{
    p.print();
}

int main(int argc, char const *argv[])
{
    String a = String("A");
    String b = String("B");
    String c;
    a.print();
    b.print();
    c.print();

    // c = A : a = null
    // c = (String &&)a;
    // a.print();
    // b.print();
    // c.print();

    // // a = B : b = null
    // a = std::move(b);
    // a.print();
    // b.print();
    // c.print();

    // // b = A : c = null
    // b = (String &&)c;
    // a.print();
    // b.print();
    // c.print();

    // A : null
    b = (String &&)b;
    b.print();

    return 0;
}
