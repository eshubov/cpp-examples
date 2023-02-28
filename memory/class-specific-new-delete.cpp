// Why would you overload operator new for a class? There are some reasons:
//
// - Performance: the default memory allocator is designed to be general purpose. 
//   Sometimes you have very specific objects you want to allocate, and by customizing the way they're allocated you can speed up memory management considerably. A lot of books and articles discuss this issue. 
//
// - Debugging & statistics: having full control of the way memory is allocated and released 
//   provides great flexibility for debugging, statistics and performance analysis. 
//   You can make your allocator insert special guards to detect buffer overruns, 
//   keep accounting of allocations vs. deallocations to detect memory leaks,
//   count various metrics for statistics and performance analysis, and much more.
//
// - Customization: for non-standard memory allocation schemes. 
//   One good example is pools or arenas for certain objects, which make memory management simpler. 
//   Another is a full-fledged garbage collection system for certain objects - 
//   this is all made possible by writing your custom operators new and delete for a class or a whole hierarchy.

// What is the expected output of the code below?

#include <iostream>
#include <vector>

class Base
{
public:
    void* operator new(size_t sz)
    {
        std::cout << "new " << sz << " bytes" << std::endl;
        return ::operator new(sz);
    }

    void operator delete(void* p)
    {
        std::cout << "delete" << std::endl;
        ::operator delete(p);
    }
private:
    int m_data;
};

class Derived : public Base
{
private:
    std::vector<int> z, y, x, w;
};

int main()
{
    Base* b = new Base;
    delete b;

    Derived* d = new Derived;
    delete d;
    return 0;
}