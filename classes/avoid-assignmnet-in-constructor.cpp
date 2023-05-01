// Avoid assignmnent in constructors. Use initializer list instead. 
// Prevent execution of default constructor.

// What will be the output?

#include <iostream> 

struct Int 
{ 
    Int() : a(0) { std::cout << "default constructor" << std::endl; } 
    Int(const int& x) : a(x) { std::cout << "constructor" << std::endl; } 
    const Int& operator=(const Int& x) 
    { 
        a = x.a; std::cout << "operator=" << std::endl; return *this; 
    } 
    int a; 
}; 

struct A 
{ 
    A(const Int& i) { a = i; } 
    Int a; 
}; 

struct B
{ 
    B(const Int& i) : a (i) {} 
    Int a; 
}; 


int main() 
{ 
    std::cout << "Constructing A" << std::endl;
    A a(1); 
    std::cout << "Constructing B" << std::endl;
    B b(1); 
    return 0; 
}
