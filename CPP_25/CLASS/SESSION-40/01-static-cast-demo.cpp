// Use case I : To make implicit type conversions explicit
// Use case II : Implicit type conversions which are valid in c but invalid
        //        In C++

/*
    Examples of implicit type conversion

    LHS = RHS

    int num;
    shor s;

    num = (int)s

    short int s = -1;

    num = s;
    void* p = exprT;
*/ 

#include <iostream>
#include <cstdlib>

void test_1();
void test_2();
void test_3();

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

int main()
{
    test_1();
    test_2();
    test_3();
    return 0;
}

void test_1()
{
    short s = -1;
    int num;
    float f_num;

    // following are the examples of implicit type conversions
    // These conversions would have been performed by compiler
    // even in the absence of implicit type casting


    num = static_cast<int>(s);
    f_num = static_cast <float>(num);

    void * p;

    p = static_cast<void*>(&num);
    p = static_cast<void*>(&f_num);
}

void test_2()
{
    int* p;
    void* q;

    // p = q; // CTE: void* to T* is not allowed to happen implicitly
    p = (int*)q; // C- style syntax

    p = static_cast <int*>(q); // c++ style syntax
    int * x = (int*)malloc(sizeof(int)); // c style

    int * y = static_cast<int*>(malloc(sizeof(int))); // C++ style 

    free(static_cast<void*>(x));
    x = 0;

    free(static_cast<void*>(y));
    y = 0;

}

void test_3()
{
    A objA;
    B objB;

    static_cast<A*>(&objB);
    (A*)(&objB);

    reinterpret_cast<A*>(&objB);
}

void f()
{
    int* p = NULL;
    int* p = 0;    // movq $0, p

    int* p = nullptr; // C++ 11 onwards
}

/*
    POSIX:
        #define NULL ((void*)0)

        struct Date* pDate = NULL;
        int*  p = NULL;
        float* fp = NULL;
*/