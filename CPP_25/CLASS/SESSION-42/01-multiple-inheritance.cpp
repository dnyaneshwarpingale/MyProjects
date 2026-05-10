#include <iostream>

class A
{
    private:
        int a, b;
    public:
        A () : a(100), b(200){
        }

        void showA()
        {
            std::cout << "a:" << a << ", b:" << b << std::endl;

        }

};

class B: public A
{
    private:
        double f1;
    
};

class C : public A
{
    private:
        double f2;
};

class D: public B, public C
{
    private:
        int a[4];
    public:
        void f()
        {

        }

};

int main()
{ 
    std::cout << "sizeof(D):" << sizeof(D) << std::endl;
    D objD;
    //objD.showA(); // CTE ambiguos access

    objD.C::A::showA(); // gives error in mingw compiler but run on the microsoft visual studio compiler
    objD.B::A::showA();

    return 0;

}

