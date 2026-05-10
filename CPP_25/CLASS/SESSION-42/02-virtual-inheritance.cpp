#include <iostream>

class A
{
    private:
        int a, b;
    public:
        A():a(100), b(200){}

        void showA()
        {
            std::cout << "a:" << a << ", b:" << b << std::endl;

        }

};

class B : virtual public A
{
    private:
        double f1;
};

class C: virtual public A
{
    private:
        double f2;
};

class E : virtual public A
{
    private:
        double d;
};

class D : public B, public C, public E
{
    private:
        int a[4];
    public:

};

int main()
{
    std::cout << "sizeof(D):" << sizeof(D) << std::endl;
    D objD;
    objD.showA();

    return 0;
};
