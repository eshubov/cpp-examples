// In Standard C++, objects defined at namespace scope are guaranteed to be initialized in an order 
// in strict accordance with that of their definitions in a given translation unit. 
// No guarantee is made for initializations across translation units. 
//
// However, GNU C++ allows users to control the order of initialization of objects defined 
// at namespace scope with the init_priority attribute by specifying a relative priority, 
// a constant integral expression currently bounded between 101 and 65535 inclusive. 
// Lower numbers indicate a higher priority.

// What will be the output?

#include <iostream>

char s[10] = {0};

void init_order(char c)
{ 
    static int i = 0;
    s[i++] = c;
    s[i] = '\0';
}    

struct A
{
    A() { init_order('A'); }
};

struct B
{
    B() { init_order('B'); }
};

struct C
{
    C() { init_order('C'); }
};

struct D
{
    D() { init_order('D'); }
};

D d;
C c;
A a  __attribute__ ((init_priority (2000)));
B b  __attribute__ ((init_priority (1999)));

int main()
{
    std::cout << s << std::endl;
    return 0;
}