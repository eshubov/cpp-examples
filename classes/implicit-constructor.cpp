// Implicit constructor is called while passing parameter by value and in return
// What will be the output?

#include <iostream>

class A 
{  
public: 
    A(int i) : a(i) {}
    A(const A& b) : a(b.a) { std::cout << "implicit constructor" << std::endl; }
    A() : a(0) {}

private: 
    int a;
}; 

void f(A a)
{
    std::cout << "Called f" << std::endl;
}

A g(A& a)
{
    std::cout << "Called g" << std::endl;
    return a;
}


int main() 
{ 
    A a(1);
    f(a);
    A b = g(a);

    return 0;   
} 
