#include<iostream>
#include<stdexcept>
#include<ctime>

void f(int n);
void g(int n);

int main()
{
    srand(time(0));
    try
    {
        f(rand());
        g(rand());
    }
    catch(const std::exception& e)
    {
        // Control flow will come here irrespective of exception type
        // This is a generic exception handler !
    }
    
}

void f(int n)
{
    if(n % 2 == 0)
        throw std::domain_error("Excpetion thrown because of even number");
    
}

void g(int n)
{
    if(n % 2 == 1)
        throw std::logic_error("Exception thrown because of odd number");
}