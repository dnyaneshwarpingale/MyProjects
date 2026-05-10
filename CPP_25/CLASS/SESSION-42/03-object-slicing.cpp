#include <iostream>

class A
{
    private:
        int num1;
        int num2;
    public:
        void f()
        {
            std::cout << "this:" << this << std::endl;
            std::cout << "&num1:" << &num1 << std::endl;

        }
};

class B : public A
{
    private:
        double d1, d2;
    public:
        B () : d1 (100.1), d2(200.1) {}

        void show()
        {
            std::cout << "d1:" << d1 << ", d2:" << d2 << std::endl;

        }

        void setd1(double _d1) { d1 = _d1;}
        void setd2(double _d2) { d2 = _d2;}

        void f()
        {
            std::cout << "this:" << this << std::endl;
            std::cout << "&d1:" << &d1 << std::endl;

        }

        B& operator=(const B& other)
        {
            std::cout << "B::operator=():" << std::endl;
            std::cout << "this:" << this << std::endl;
            std::cout << "&other:" << &other << std::endl;
            this->d1 = other.d1;
            this->d2 = other.d2;

            return *this;

        }

};

class C : public  B
{
    private:
        int a[4];
    public:
        void f()
        {
            std::cout << "this:" << this << std::endl;
            std::cout << "&a[0]" << &a[0] << std::endl;
        }
};

class D : public C
{
    private:
        int n1, n2;
    public:
        void f()
        {
            std::cout << "this:" << this << std::endl;
            std::cout << "&n1:" << &n1 << std::endl;

        }
};

void test();

int main()
{
    test();
    return 0;

}

void test()
{
    D objD;
    
    A* pA = &objD;
    B* pB = &objD;
    C* pC = &objD;
    D* pD = &objD;

    std::cout << "&objD:" << &objD << std::endl;
    pA->f();
    pB->f();
    pC->f();
    pD->f();

    B objB;
    objB.setd1(10000.1);
    objB.setd2(20000.2);
    objD.setd1(155.67);
    objD.setd2(243.12);

    objB.show();

    objB = objD;
    objB.show();

    void* p = reinterpret_cast <void*>(&objD);

    std::cout << reinterpret_cast<char*>(p) + 8 << std::endl;
    std::cout << reinterpret_cast<char*>(p) + 24 << std::endl;
    std::cout << reinterpret_cast<char*>(p) + 40 << std::endl;
}