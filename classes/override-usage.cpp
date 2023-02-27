// In a member function declaration or definition, override specifier ensures that the function is virtual 
// and is overriding a virtual function from a base class. 

// Which lines produce compilation errors?

#include <iostream>
 
struct A
{
    virtual void foo();
    void bar();
    virtual ~A();
};
 
void A::foo() { std::cout << "A::foo();\n"; }
A::~A() { std::cout << "A::~A();\n"; }
 
struct B : A
{
    void foo() const override;
    void foo() override;
    void bar() override;
    ~B() override;
};
 
void B::foo() { std::cout << "B::foo();\n"; }
B::~B() { std::cout << "B::~B();\n"; }
 
int main()
{
    B b;
    b.foo();
    return 0;
}