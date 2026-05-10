#include <iostream>

class C1
{
    private:
        int c1_private_num;
    protected:
        int c1_protected_num;
    public:
        void f()
        {
            std::cout <<"C1::f()" << std::endl;

        }
        virtual void g()
        {
            std::cout  << "C1::g()" << std::endl;

        }
        void h1()
        {
            std::cout << "C1::h1()" << std::endl;
        }
};

class C2 : private C1
{
    private:
        int c2_private_num;
    protected:
        int c2_protected_num;
    public:
      void f()
        {
            std::cout <<"C2::f()" << std::endl;

        }
        void g()
        {
            std::cout  << "C2::g()" << std::endl;

        }
        void h2()
        {
            std::cout << "C2::h2()" << std::endl;
        }
};

class C3 : protected C2
{
    private:
        int c3_private_num;
    protected:
        int c3_protected_num;
    public:
        void f()
        {
            std::cout <<"C3::f()" << std::endl;

        }
        void g()
        {
            std::cout  << "C3::g()" << std::endl;

        }
        void h3()
        {
            std::cout << "C3::h3()" << std::endl;
        }
};

class C4 : public C3
{
    private:
        int c4_private_num;
    protected:
        int c4_protected_num;
    public:
        void f()
        {
            std::cout <<"C4::f()" << std::endl;

        }
        void g()
        {
            std::cout  << "C4::g()" << std::endl;

        }
        void h4()
        {
            std::cout << "C4::h4()" << std::endl;
        }

        void c4_test()
        {
            this->h4();
            this->h3();
            this->h2();

            // this->h1(); // CTE c2 privately inherits
            this->c4_protected_num = 10;
            this->c4_private_num = 20;
            this->c3_protected_num = 30;
            this->c2_protected_num = 40;
                 // this->c1_protected_num = 50; // CTE C2 privatelt inherits C1 
        }
};

int main()
{
    C4 objC4;

    objC4.h4();
    objC4.h3();
     //objC4.h2();     // CTE C3 inherits C2 in protected manner
     return 0;
}