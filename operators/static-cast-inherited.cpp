// Change one word in this code to have it compiled

#include <iostream>

using namespace std;
  
class Base  {};
  
class Derived: protected Base {};
  
int main()
{    
  Derived d1;   
  Base* b2 = static_cast<Base*>(&d1);

  return 0;
}









// EXPLANATION:
// ------------
//
// static_cast fails if base class is privately inherited.
// Use public inheritence to make static_cast work:
//     class Derived: public Base {};






