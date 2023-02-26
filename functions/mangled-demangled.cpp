#include <iostream>
#include <cxxabi.h>

extern "C" int function1();

namespace some_name {

int function2(int, int) {
    return 0;
}

class A {

public:
  void function3() {}
};

}

int main() 
{
    int status;

    std::cout << "Mangled: " << typeid(&function1).name() << ", demangled:" << abi::__cxa_demangle(typeid(&function1).name(), 0, 0, &status) << std::endl;
    std::cout << "Mangled: " << typeid(&some_name::function2).name() << ", demangled:" << abi::__cxa_demangle(typeid(&some_name::function2).name(), 0, 0, &status)<< std::endl;
    std::cout << "Mangled: " << typeid(&some_name::A::function3).name() << ", demangled:" << abi::__cxa_demangle(typeid(&some_name::A::function3).name(), 0, 0, &status)<< std::endl;

    return 0;
}