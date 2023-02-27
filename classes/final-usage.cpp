// When used in a virtual function declaration or definition, 
// final specifier ensures that the function is virtual and specifies that it may not be overridden by derived classes. 
// 
// When used in a class definition, 
// final specifies that this class may not appear in the base-specifier-list of another class definition (in other words, cannot be derived from)

// Which lines produce compilation errors?

struct Base
{
    virtual void foo();
};
 
struct A : Base
{
    void foo() final;
    void bar() final;
};
 
// struct B is final 
struct B final : A 
{
    void foo() override;
};
 
struct C : B {};

