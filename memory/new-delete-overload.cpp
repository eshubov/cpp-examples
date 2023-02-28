// Overloading new and delete operators might be used for debugging

// What is the expected output of this code?

#include <iostream>

void* operator new(size_t sz) throw ()
{
    std::cerr << "allocating " << sz << " bytes" << std::endl;
    void* mem = malloc(sz);
    if (mem)
        return mem;
    else
        throw std::bad_alloc();
}


void operator delete(void* ptr) throw ()
{
    std::cerr << "deallocating at " << ptr << std::endl;
    free(ptr);
}

int main()
{
    int* x = new int(10);
    int* a = new int[10];
    delete x;
    delete [] a;
    return 0;
}


