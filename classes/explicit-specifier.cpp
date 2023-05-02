// Explict specifies that a constructor or conversion function is explicit, 
// that is, it cannot be used for implicit conversions and copy-initialization.
// error: copy-initialization does not consider B::B(int)
//
// QUESTION:
// ---------
// What lines will cause compilation errors?

struct A 
{ 
    A(int) {} 
    operator bool() const { return true; } 
}; 

struct B 
{ 
    explicit B(int) {} 
    explicit operator bool() const { return true; } 
};

int main() 
{ 
    A a1 = 1;
    A a2(2);
    A a5 = (A)1;
    if (a1) { }
    bool na1 = a1; 
    bool na2 = static_cast<bool>(a1); 

    B b1 = 1; 
    B b2(2);
    B b5 = (B)1;
    if (b2) { }
    bool nb1 = b2;
    bool nb2 = static_cast<bool>(b2); 
}
