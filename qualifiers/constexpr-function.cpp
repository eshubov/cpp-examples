#include <iostream>

// Which of factorial calls will be evaluated at compile time, and which at run time?

// C++11 constexpr functions use recursion rather than iteration
constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}
 
// output function that requires a compile-time constant, for testing
template<int n>
struct constN
{
    constN() { std::cout << n << '\n'; }
};

int main()
{
    std::cout << "4! = ";
    constN<factorial(4)> out1;

    int k = 3;
    int i = factorial(k);
    switch(i)
    {
        case factorial(1):
            std::cout << "1! = "; break;
        case factorial(2):
            std::cout << "2! = "; break;
        case factorial(3):
            std::cout << "3! = "; break;
    }

    std::cout << i << '\n';
  
    return 0;
}