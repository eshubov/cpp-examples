// Run 'size -A -d <exe> and see sizes of .data and .rodata sections with and without const

// What will be the output of this program?

#include <iostream>

const char x[] = "?ello, world\n";

int main()
{
    *(const_cast<char*>(x)) = 'H';
    std::cout << x;
    return 0;
}