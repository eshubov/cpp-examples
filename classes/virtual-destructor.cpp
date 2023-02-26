// The important thing to note here is the order of destruction of classes 
// and how Base’s method reverts back to its own implementation once A has been destroyed.

// What will be the output?
// What will be the output if destructor is not virtual?

#include <iostream>

class Base {
    virtual void method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "from A" << std::endl;}
public:
    ~A() {method();}
};

int main(void) 
{
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}