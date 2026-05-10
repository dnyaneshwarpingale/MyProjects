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
    catch(const std::logic_error& e)
    {
       // control flow will come here in both case
       // logic_error is thrown | domain_error is thrown

    }
    catch(const std::domain_error& e)
    {
        // control flow will never come here
        // because even if domain_error exception is thrown
        // in function f() it will match with the first catch 
        // block, because a reference variable of the type logic_error
        // can refer to object of type domain_error.
    }
    
}

void f(int n)
{
    if(n %2 == 0)
        throw std::domain_error("Exception thrown because of even number");

}

void g(int n)
{
    if(n % 2 == 1)
        throw std::logic_error("Exception thrown because of odd number");
        
}