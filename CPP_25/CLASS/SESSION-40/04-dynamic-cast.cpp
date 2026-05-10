#include <iostream>

class Base
{
    public:
        virtual void f()
        {
            std::cout << "Base::f()" << std::endl;
        }
};

class Derived : public Base
{
    public:
        void f()
        {
            std::cout << "Derived :: f()" << std::endl;
        }

        void g()
        {
            std::cout << "Derived :: g()" << std::endl;
        }
};

class XYZ
{
    public:
        void h()
        {
            std::cout <<"XYZ::h()" << std::endl;
        }
};

int main()
{
    Base* pBase = new Derived;
    pBase->f();  // Derived::f()
    pBase->g(); // Fails

    ((Derived*)pBase)->g();  // Work
    reinterpret_cast <Derived*>(pBase)->g();
    
    reinterpret_cast<XYZ*>(pBase)->h();

    dynamic_cast<XYZ*>(pBase)->h(); // not okay

    delete pBase;
    pBase = 0;
    return 0;

}