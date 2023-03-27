// What will be the output of the following code?

#include <iostream>
#include <string>
using namespace std;
  
class integer {
    int x;
  
public:
    integer(int x_in = 0)
        : x{ x_in }
    {
        cout << "Constructor Called" << endl;
    }
  
    operator string()
    {
        cout << "Conversion Operator Called" << endl;
        return to_string(x);
    }
};
  
int main()
{
    integer obj(3);
    string str = obj;
    obj = 20;
  
    string str2 = static_cast<string>(obj);
    obj = static_cast<integer>(30);
  
    return 0;
}