// Raw operators new and delete act as a raw memory allocator, similar to malloc/free.
// Do not confuse operator new/delete with new/delete keywords. 

// What will be the output?

#include <iostream>

struct A
{
    A(int&& x) : a(x) { std::cout << "I am A" << std::endl; } 
    int a;
};

int main()
{
    A* v0 = static_cast<A*>(::operator new(sizeof(*v0)));
    ::operator delete(v0);

    A* v1 = new A(10);
    delete v1;

    return 0;
}    