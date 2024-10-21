#include <iostream>

class Base
{
public:
    virtual void func() { std::cout << "Base" << std::endl; }
};

class Derived : public Base
{
public:
    void func() override { std::cout << "Derived" << std::endl; }
};

int main()
{
    Base *basePtr = new Derived();
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

    if (derivedPtr != nullptr)
    {
        derivedPtr->func(); // Output: Derived
    }

    delete basePtr;

    return 0;
}