#include <iostream>
#include <cstdlib>

class A 
{
    public:
        void f()
        {
            std::cout << "A::f()" << std::endl;

        }

};

class B 
{
    public:
        void g()
        {
            std::cout << "B::g()" << std::endl;
        }
};

void test_1();
void test_2();

int main()
{
    test_1();
    test_2();

    return 0;
}

void test_1()
{
    unsigned long long int x = 0;
    
    // When you are using free-style type casting
    // two unrelated types are involved
    *reinterpret_cast<short*>(reinterpret_cast<char*>(&x) + 1) = 0xFFFF;
}

void test_2()
{
    A objA;

    reinterpret_cast<B*>(&objA)->g();
}