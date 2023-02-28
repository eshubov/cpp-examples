// This feature has been here since C++98, where the compiler would try to generate:
//
// - a default constructor X(), that calls the default constructor of each class member and base class,
// - a copy constructor X(X const& other), that calls a copy constructor on each member and base class,
// - a copy assignment operator X& operator=(X const& other), that calls a copy assignment operator on each class member and base class,
// - the destructor ~X(), that calls the destructor of each class member and base class. Note that this default-generated destructor is never virtual (unless it is for a class inheriting from one that has a virtual destructor).
// With C++11, the compiler generates 2 new functions related to move semantics:
// 
// - a move constructor X(X&& other), that calls a move constructor of each class member and base class,
// - a move assignment operator X& operator=(X&& other), that calls a move assignment operator on each class member and base class.

// Fix compilation error and predict output

#include <iostream>

class A
{
public:    
    A(int i) : a(i) { std::cout << "A::(" << i << ")" << std::endl; }
    A() = default;
    A& operator=(const A& other) { a = other.a; return *this; }
    A& operator=(A&& other) = delete; //{ a = other.a; return *this; }
private:    
    int a;
};


int main()
{
    A a0, a1;
    std::cout << "This is main" << std::endl;   
    a0 = 1;
    a1 = a0;
    return 0;
}