// Why use static_cast<int>(x) instead of (int)x?
// The main reason is that classic C casts make no distinction between what we call static_cast<>(),
// reinterpret_cast<>(), const_cast<>(), and dynamic_cast<>(). 
// These four things are completely different.
// A static_cast<>() is usually safe. There is a valid conversion in the language, or an appropriate
// constructor that makes it possible.
// A reinterpret_cast<>() (or a const_cast<>()) on the other hand is always dangerous. You tell the
// compiler: "trust me: I know this doesn't look like a foo (this looks as if it isn't mutable), but it is".

// Which line of code will gejerate compiler error?

class CMyBase {};
class CMyClass : public CMyBase {};
class CMyOtherStuff {};

int main()
{
    CMyBase *pSomething;
    CMyClass *pMyObject;
    CMyOtherStuff *pOther;
    pMyObject = static_cast<CMyClass*>(pSomething);
    pMyObject = reinterpret_cast<CMyClass*>(pSomething);
    pMyObject = (CMyClass*)(pSomething);

    pOther = static_cast<CMyOtherStuff*>(pSomething);
    pOther = reinterpret_cast<CMyOtherStuff*>(pSomething);
    pOther = (CMyOtherStuff*)(pSomething);
    return 0;
}