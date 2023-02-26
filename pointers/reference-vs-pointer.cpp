#include <iostream>

void f(int* i)
{
    // Can't trust callee that the pointer is initialized
    if (nullptr != i)
        *i = 1;
}

void g(int& i)
{
    // No need to check reference validity
    // C++ doesn't allow unitialized refernces
    i = 2;
}

int main()
{
    int j = 1;
    f(&j);
    std::cout << "j=" << j << std::endl;
    g(j);
    std::cout << "j=" << j << std::endl;
    return 0;
}