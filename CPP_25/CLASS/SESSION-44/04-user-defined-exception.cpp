#include<iostream>
#include <stdexcept>
#include <typeinfo>

class negative_number_error : public std::domain_error
{
    public:
        negative_number_error(const char* msg) : std::domain_error(msg)
        {

        }
};

double my_sqrt(double x);

int main()
{
    try
    {
        my_sqrt(-1.0);
    }
    catch(const negative_number_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unanticipated exception:" << typeid(e).name() << "was thrown" <<std::endl;
    }
    
    return 0;
}

double my_sqrt(double x)
{
    if(x < 0.0)
        throw negative_number_error("sqrt of negative number cannot number be computed");
        
    std::cout << "Computing sqrt of :"<< x << std::endl;
    return 0.0;
}