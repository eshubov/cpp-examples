// mutable - permits modification of the class member declared mutable even if the containing object is declared const.
// volatile - suppresses register optimization

// Which lines will generate compilation errors?

#include <cstdlib>
 
int main()
{
    int n1 = 0;          // non-const object
    const int n2 = 0;    // const object
    volatile int n4 = 0; // volatile object
 
    const struct
    {
        int n1;
        mutable int n2;
    } x = {0, 0};        // const object with mutable member
 
    n1 = 1;
    n2 = 2;
    n4 = 3;
    x.n1 = 4;
    x.n2 = 4;
    const int& r1 = n1;
    r1 = 2;
    const_cast<int&>(r1) = 2;
    const int& r2 = n2;
    r2 = 2;
 
    std::system("g++ -O3 -Wa,-adhln " __FILE__); // may issue asm on POSIX systems
    // # typical machine code produced on an x86_64 platform
    // # (only the code that contributes to observable side-effects is emitted)
    // main:
    //    movl    $0, -4(%rsp) # volatile int n4 = 0;
    //    movl    $3, -4(%rsp) # n4 = 3;
    //    xorl    %eax, %eax   # return 0 (implicit)
    //    ret
}