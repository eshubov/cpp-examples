// Advantages of placement new operator over new operator
//
// The address of memory allocation is known before hand.
// Useful when building a memory pool, a garbage collector or simply when performance and exception safety are paramount.
// There’s no danger of allocation failure since the memory has already been allocated, and constructing an object on a pre-allocated buffer takes less time.
// This feature becomes useful while working in an environment with limited resources.

// What will be the output of this code, and what should be done to correct it?

#include <iostream>
#include <new>

struct A
{
    A(int&& x) : a(x) {}
    ~A() { std::cout << "I am destructed" << std::endl; }
    int a;
};


int main()
{
    // A "normal" allocation. Asks the OS for memory, so we
    // don't actually know where this ends up pointing.
    A* a0 = new A(1);

    // Create a buffer large enough to hold an integer, and
    // note its address.
    unsigned char mem[sizeof(A)];

    // Construct the new integer inside the buffer 'mem'.
    // The address is going to be mem's.
    A* a1 = new ((void*)mem) A(10);

    delete a0;
    delete a1;

    return 0;
}