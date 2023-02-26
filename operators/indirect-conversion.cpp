// The conversion to bool enables clients to use smart pointers in expressions that require bool operands

#include <iostream>

template <typename T> 
class Ptr 
{  
public: 
    Ptr(T *p) : p(p) {}
    Ptr() : p(&t) {}

    operator bool() const { return p != &t ? true : false; }

    T& operator*() const { return *p; }
private: 
    T* p; 
    static T t;
}; 

template<typename T> T Ptr<T>::t = 0;

int main() 
{ 
    Ptr<int> ptr(new int(1)); 

    if (ptr) //calls operator bool() 
        std::cout << *ptr << std::endl; 
    else 
        std::cout << "empty" << std::endl; 

    Ptr<unsigned> pc;
    std::cout << *pc << std::endl;    

    return 0;   
} 
