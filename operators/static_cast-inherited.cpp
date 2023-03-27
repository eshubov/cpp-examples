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