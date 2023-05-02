#include <iostream>

// In contrary to const, constexpr is evaluated at compilation time.

// QUESTION:
// ---------
// What should be changed in this code to solve compilation error?
//
// Which of factorial calls will be evaluated at compile time, and which at run time?
// How to prove that?

// C++11 constexpr functions use recursion rather than iteration
const int factorial(int n)
{
    // "g++ -std=c++11 constexpr-function.cpp" will fail as only return statement is supported in C++11
    if (n <= 1) return 1; else return (n * factorial(n - 1)); 

    // This will work also with C++11
    //return n <= 1 ? 1 : (n * factorial(n - 1));
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








// ANSWER:
// -------
// constexpr int factorial(int n)