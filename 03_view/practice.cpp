
#include <iostream>

class Base {
public:
    int data;
    virtual void    function();
};

void    Base::function()
{
    std::cout << "print hello from base" << std::endl;
}

class A : virtual public Base {
    public:
        void    function() override;
};

void    A::function()
{
    std::cout << "print hello from A" << std::endl;
}

class B : virtual public Base {
};

class Derived : public A, public B {
};

int main() {
    Derived d;
    d.A::data = 5;
    d.B::data = 10;
	// d.A::data = 2;
    d.function();
    std::cout << d.A::data << std::endl;  // Outputs 10
    std::cout << d.B::data << std::endl;  // Outputs 10

    // std::cout << d.A::data << std::endl;  // Outputs 10
    // std::cout << d.B::data << std::endl;  // Outputs 10
    return 0;
}
