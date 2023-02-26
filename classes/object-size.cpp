#include <iostream>

class A
{ 
    char a; 
    size_t b; 
}; 

class B 
{ 
    size_t b; 
    void f(); 
}; 

class C
{ 
    size_t b; 
    virtual void f(); 
}; 

class D
{ 
    size_t b; 
    virtual void f(); 
    virtual void g();
}; 

class E
{ 
}; 

class F : public D
{ 
    size_t b; 
};

int main()
{
    std::cout 
        << "A=" << sizeof(A) << std::endl
        << "B=" << sizeof(B) << std::endl
        << "C=" << sizeof(C) << std::endl
        << "D=" << sizeof(D) << std::endl
        << "E=" << sizeof(E) << std::endl
        << "F=" << sizeof(F) << std::endl;
    return 0;
}
