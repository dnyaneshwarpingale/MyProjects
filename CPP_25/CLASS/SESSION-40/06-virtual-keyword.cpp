#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class B
{
    public:
        void f()
        {
            std::cout << "B::f()" << std::endl;
        }

        virtual ~B(){}
};

class D1 : public B
{
    public:
        void f()
        {
            std::cout << "D1::f()" << std::endl;
        }
};

class D2 : public B
{
    public:
        void f()
        {
            std::cout << "D2::f()" << std::endl;
        }
};

class D3 : public B 
{
    public:
        void f()
        {
            std::cout << "D3::f()" << std::endl;
        }
};

int main (void)
{
    B* pB = 0;
    srand(time(0));

    int n = rand() % 4;

    switch(n)
    {
        case 0:
            pB = new B;
            break;
        case 1:
            pB = new D1;
            break;
        case 2:
            pB = new D2;
            break;
        case 3:
            pB = new D3;
            break;
    }

    // I don't know the type of object pB contains
    // may be B, or D1,or D2, or D3

    pB->f(); // B::f()

    std::cout << "typid(*pB):" << typeid(*pB).name() << std::endl;

    if(typeid(*pB) == typeid(B))
        pB->f();
    else if(typeid(*pB) == typeid(D1))
        reinterpret_cast<D1*>(pB)->f();
    else if( typeid(*pB) == typeid(D2))
        reinterpret_cast<D2*>(pB)->f();
    else if( typeid(*pB) == typeid(D3))
        reinterpret_cast <D3*>(pB)->f();

    delete pB;
    pB = 0;
    
}