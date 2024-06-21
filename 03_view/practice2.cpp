#include <iostream>

class Base {
protected:
    int A;
    int B;
    int C;
public:
	Base() : A(0), B(0), C(0) {std::cout << A << B << C << "base def constuctor" << std::endl;}
    Base(int a, int b, int c) : A(a), B(b), C(c) {std::cout << "base para constuctor" << std::endl;}
    int getA() const { return A; }
    int getB() const { return B; }
    int getC() const { return C; }
};

class Derived2 : public Base {
public:
    Derived2() : Base(100, 100, 100) {std::cout << "Derived2 para constuctor" << std::endl;} // Initializes A and B
};

class Derived3 : public Base {
public:
    Derived3() : Base(222, 222, 222) {std::cout << "Derived3 para constuctor" << std::endl;} // Initializes C
};

class Derived4 : public Derived2, public Derived3{
public:
    Derived4() : Derived2(), Derived3()
	{
		std::cout << "Derived4 def constuctor" << std::endl;} // Choose which initialization to use
};

int main() {
    Derived4 d4;
    std::cout << "A: " << d4.Derived2::getA()<< ", B: " << d4.Derived2::getB() << ", C: " << d4.Derived3::getC() << std::endl;	
    return 0;
}
