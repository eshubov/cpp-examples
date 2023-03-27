// In case static_casting from derived class the pointer address is changed

// What will be the output of the following code?

#include <iostream>
#include <iomanip>
using namespace std;

class A
{
public:
    int i;
};

class B : public A
{
public:
    virtual void f() {}
};

int main()
{
    B b;
    b.i = 0;
    A* as = static_cast<A*>(&b);
    A* ar = reinterpret_cast<A*>(&b);
    B* ab = reinterpret_cast<B*>(ar);

    cout << "as == ar ? " << (as == ar) << endl; 
    cout << "ab == ar ? " << (ab == ar) << endl; 
    cout << "reinterpret_cast<A*>(ab) == ar ? " << (reinterpret_cast<A*>(ab) == ar) << endl; 

    // cout << "as = " << as << endl;
    // cout << "ar = " << ar << endl;
    // cout << "ab = " << ab << endl;

    cout << "as->i = " << as->i << endl;
    cout << "ar->i = " << ar->i << endl;
    cout << "ab->i = " << ab->i << endl;

    return 0;
}