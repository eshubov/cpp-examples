// What will be the output?

#include <iostream>

struct Int { 
    Int(int a) : a(a) { std::cout << "Int" << std::endl; }
    int a; 
}; 

struct Float { 
    Float(float a) : a(a) { std::cout << "Float" << std::endl; }
    int a; 
}; 

struct A { 
    A(int a, float b) : b(b), a(a) {} 
    Int a; 
    Float b; 
}; 

int main() 
{ 
    A a(1, 20); 
    return 0; 
}
