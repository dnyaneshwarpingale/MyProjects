#include <iostream>

class IX
{
    public:
        virtual void f1() = 0;
        virtual void f2() = 0;
};

class IY
{
    public:
        virtual void g1() = 0;
        virtual void g2() = 0;
};

class C : public IX, public IY
{
    private:
        int num1, num2, num3, num4;
    public:
        C() : num1(100),num2(200),num3(300),num4(400)
        {

        }

        void f1()
        {
            std::cout << "C1::f1():num1:" << num1 << std::endl;

        }

        
        void f2() 
        {
            std::cout << "C1::f2():num1:" << num1 << std::endl;  
        }

        void g1() 
        {
            std::cout << "C1::g1():num1:" << num1 << std::endl;  
        }

        void g2() 
        {
            std::cout << "C1::g2():num1:" << num1 << std::endl;  
        }
};

int main()
{
    C* pC = new C;

    dynamic_cast<IX*>(pC)->f1();
    dynamic_cast<IX*>(pC)->f2();
    dynamic_cast<IY*>(pC)->g1();
    dynamic_cast<IY*>(pC)->g2();

    IX* pX = pC;
    IY* pY = pC;

    pX->f1();
    pX->f2();

    pY->g1();
    pY->g2();

    std::cout << "pX: "<< std::dec <<pX << std::endl;
    std::cout << "pY:" << std::dec << pY << std::endl;
    std::cout << "pC:" << std::dec << pC << std::endl;

    std::cout << "sizeof C:" << sizeof(C) << std::endl;

    delete pC;
    pC = 0;
}