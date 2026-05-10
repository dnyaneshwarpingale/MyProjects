#include <iostream>
#include <stdexcept>

double my_sqrt(int X);
void helper_1(int);
void helper_2(int);
void helper_3(int);
void helper_4(int);

int main(void)
{
    int arr[] = { 100, 200, -300, 400, 500, -600, -700, 800};
    int i;
    int ret_val;

    i = 0;

    while(i < 8)
    {
        double ans ;
        try
        {
            ans = my_sqrt(arr[i]);
            std::cout << "ans:" << ans << std::endl;

        }catch(const std::domain_error& e)
        {
            std::cerr << e.what() << std::endl;

        }
        i = i+1;

    }
    std::cout << "Got Out of While Loop " << std::endl;
    // double y = my_sqrt(-50.0); // Uncomment this line to experience
                                  // Uncaught or unhandled exception 
                                  
    std::cout << "Successful End of Application" << std::endl;
    return (0);
}

double my_sqrt(int x)
{
    puts("my_sqrt() : Befor helper_1()");
    helper_1(x);
    puts("my_sqrt():After helper_1()");
    return 0.0;
}

void helper_1(int x)
{
    puts("helper_1(): Before helper_2()");
    helper_2(x);
    puts("helper_1():After helper_2");

}

void helper_2(int x)
{
    puts("helper_2():Before helper_3()");
    helper_3(x);
    puts("helper_2():After helper_3()");

}

void helper_3(int x)
{
    puts("helper_4():Before helper_4()");
    helper_4(x);
    puts("helper_3():After helper_4()");
}

void helper_4(int x)
{
    puts("helper_4():Before Error Detection");
    if(x < 0)
    {
        throw std::domain_error("non-negative number was expected, negative number was given");

    }
    puts("helper_4():After Error Detection");
}