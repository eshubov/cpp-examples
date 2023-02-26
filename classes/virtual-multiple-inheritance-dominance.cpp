// What will be the output?

#include <iostream>

struct A
{ 
    void f() { std::cout << "A!" << std::endl; } 
}; 

struct B : virtual A 
{ 
    void f() { std::cout << "B!" << std::endl; } 
}; 

struct C : virtual A { }; 

// name-lookup sees B::f and A::f, but B::f dominates over A::f ! 
struct D : B, C 
{ 
    void g() { f(); } 
};

int main()
{
    D d;
    d.g();
    return 0;
}
