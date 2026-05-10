#include <iostream>
#include "max.hpp"

void test(void);

int main(void)
{
    test();
    return EXIT_SUCCESS;
}

void test(void)
{
    int max_integer;
    float max_float;
    std::string max_string;

    int m = 100, n =50;
    float f_num1= 1.1, f_num2=2.2;
    std::string s1 = "world";
    std::string s2 = "Hello";

    max_integer = ::max<int>(m,n);
    max_float = :: max <float>(f_num1, f_num2);
    max_string = ::max<std::string>(s1,s2);

    std::cout << "max(m,n):" << max_integer << std::endl
                <<"max(f_num1, f_num2):" << max_float << std::endl
                <<"max(hello, world):" << max_string << std::endl;

    max_integer = ::max<int>(50,20);
    max_float = :: max <float>(3.3f, 1.1f);
    max_string = ::max<std::string>("Hello","World");

    std::cout << "max(m,n):" << max_integer << std::endl
                <<"max(f_num1, f_num2):" << max_float << std::endl
                <<"max(hello, world):" << max_string << std::endl;

                

    max_integer = ::max(100,200);
    max_float = :: max(6.6f, 2.2f);
    max_string = ::max(std::string("Hello"),std::string("World"));

    std::cout << "max(m,n):" << max_integer << std::endl
                <<"max(f_num1, f_num2):" << max_float << std::endl
                <<"max(hello, world):" << max_string << std::endl;

}