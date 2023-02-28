// int&& a means "a" is an r-value reference. 
// && is normally only used to declare a parameter of a function. 
// And it only takes a r-value expression. If you don't know what an r-value is, the simple explanation is that it doesn't have a memory address. 
// E.g. the number 6, and character 'v' are both r-values. int a, a is an l-value, however (a+2) is an r-value.

// Which lines will prduce compilation errors?

void foo(int&& a)
{
    //Some magical code...
}

int main()
{
    int b;
    foo(b);
    foo(5);
    foo(b+3);

    int&& c = b;
    int&& d = 5;

    return 0;
}