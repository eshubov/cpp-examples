// Postfix operator requires integer argument.
// Postfix increment and decrement operators are less efficient as they require to create a copy of an object.

// What will be the output of the following code?

#include <iostream>

class Int
{
public:
    Int(int i = 0) : _i(i) {}

    Int operator++( int n ) // Postfix increment operator
    { 
        Int ret(_i); 
        if (n != 0)
            _i += n;
        else     
            _i++; 
        return ret; 
    }

    Int& operator++() // Prefix increment operator
    { 
        ++_i; 
        return *this; 
    }

    operator int() { return _i; }

private:
    int _i;
};

int main()
{
   Int i;
   std::cout << i++ << std::endl;
   std::cout << ++i << std::endl;
   std::cout << i.operator++( 25 ) << std::endl;
   std::cout << i.operator++() << std::endl;
   std::cout << i.operator++(0) << std::endl;
   std::cout << i << std::endl;
}