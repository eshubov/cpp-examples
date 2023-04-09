// Why are const Functions used in C++?
// We use const member functions in C++ to avoid accidental object changes. 
// It is highly recommended to make as many functions const as possible so that the chances of error in the program are minimal.
//
// Const Member Function Use Cases
// The two use cases of the const member function are as follows:
// - A const member function is called by any type of object, i.e., either by a const or a non-const object.
// - A non-const function can only be called by a non-const object, and a const function cannot call it.

// Which lines of code will provide compilation errors?

#include <iostream>

using namespace std;

class Example {
    int x;
public:
    Example() : x(0) {}
    void set_value(int a) { x = a; }
    int get_square() { return x*x; }
    int get_value() const { return x; }
};

int main()
{
   Example obj1;
   const Example obj2;
   obj1.set_value(2);
   obj2.set_value(3);
   cout << obj1.get_square() << endl;
   cout << obj2.get_value() << endl;
   cout << obj1.get_value() << endl;
   cout << obj2.get_square() << endl;
 
   return 0;
}