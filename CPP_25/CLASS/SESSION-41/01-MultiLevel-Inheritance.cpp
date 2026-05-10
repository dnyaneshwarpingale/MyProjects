#include <iostream>

class C1
{
    public:
        void f()
        {
            std::cout << "C1::f()" << std::endl;
        }

        virtual void g()
        {
            std::cout << "C1::g()" << std::endl;

        }

        void h1()
        {
            std::cout << "C1::h1()" << std::endl;
        }
};

class C2 : public C1
{
    public:
     void f()
     {
            std::cout << "C2::f()" << std::endl;  
     }

     void g()
     {
        std::cout << "C2::g()" << std::endl;
     }

     void h2()
     {
        std::cout << "C2::h2()" << std::endl;
     }

};

class C3 : public C2
{
    public:
        void f()
        {
            std::cout << "C3::f()" << std::endl;
        }

        void g()
        {
            std::cout << "C3::g()" << std::endl;
        }

        void h3()
        {
            std::cout << "C3::h3()" << std::endl;
        }
};

class C4 : public C3
{
    public:
        void f()
        {
            std::cout << "C4::f()" << std::endl;
        }

        void g()
        {
            std::cout << "C4::g()" << std::endl;
        }

        void h4()
        {
            std::cout << "C4::h4()" << std::endl;
        }
};

void test_1();
void test_2();
void test_3();
void test_4();

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();

    return 0;
}

void test_1()
{
    std::cout << "--------Entered test_1()-------" << std::endl;
    C1* pC1 = new C4;

    std::cout << "---All C1 member functions---" << std::endl;
    pC1->f();
    pC1->C1::g();
    pC1->h1();
    std::cout << "--All C2 member functions------" << std::endl;

    dynamic_cast <C2*>(pC1)->f();
    dynamic_cast <C2*>(pC1)->C2::g();
    dynamic_cast <C2*>(pC1)->h2();
    std::cout << "---All C3 member functions----" << std::endl;

    dynamic_cast<C3*>(pC1)->f();
    dynamic_cast<C3*>(pC1)->C3::g();
    dynamic_cast<C3*>(pC1)->h3();

    std::cout << "-------All C4 member functions------" << std::endl;
    dynamic_cast<C4*>(pC1)->f();
    pC1->g();
    dynamic_cast <C4*>(pC1)->h4();
    
    delete pC1;
    pC1 = 0;

    std::cout << "------Leaving test_1()-------" << std::endl;

}

void test_2()
{
    std::cout << "-----------Entered test_2()-----" << std::endl;
    C2* pC2 = new C4;

    std:: cout << "All C1 member functions------" << std::endl;

    pC2->C1::f();
    pC2->C1::g();
    pC2->h1();
    std::cout << "----All C2 member functions-----" << std::endl;
    pC2->f();
    pC2->C2::g();
    pC2->h2();
    std::cout << "------All C3 member functions-------" << std::endl;
    dynamic_cast<C3*> (pC2)->f();
    dynamic_cast<C3*> (pC2)->C3::g();
    dynamic_cast<C3*> (pC2)->h3();
    std::cout << "-------All C4 member functions------" << std::endl;
    
    dynamic_cast<C4*> (pC2)->f();
    dynamic_cast<C4*> (pC2)->C4::g();
    dynamic_cast<C4*> (pC2)->h4();

    delete pC2;
    pC2 = 0;
    std::cout << "----------Leaving test_2()--------" << std::endl;
}

void test_3()
{
    std::cout << "-------------Entered test_3()--------" << std::endl;
    C3* pC3 = new C4;

    std::cout << "------All C1 member functions------" << std::endl;
    pC3->C1::f();
    pC3->C1::g();
    pC3->h1();
    std::cout << "---------All C2 member functions-----" << std::endl;
    pC3->C2::f();
    pC3->C2::g();
    pC3->h2();
    std::cout << "---------All C3 member functions------" << std::endl;
    pC3->f();
    pC3->C3::g();
    pC3->h3();
    std::cout << "----------All C4 member functions------" << std::endl;
    dynamic_cast<C4*> (pC3)->f();
    dynamic_cast<C4*> (pC3)->C4::g();
    dynamic_cast<C4*> (pC3)->h4();

    delete pC3;
    pC3 = 0;
    std::cout << "Leaving test_3()---------" << std::endl;  
}

void test_4()
{
    std::cout << "----------Entered test_4()------------" << std::endl;
    C4* pC4 = new C4;
    std::cout << "-------All C1 Member functions-------" << std::endl;
    pC4->C1::f();
    pC4->C1::g();
    pC4->h1();
    std::cout << "-------All C2 Member functions-------" << std::endl;
    pC4->C2::f();
    pC4->C2::g();
    pC4->h2();

    std::cout << "-------All C3 Member functions-------" << std::endl;
    pC4->C3::f();
    pC4->C3::g();
    pC4->h3();
    std::cout << "-------All C4 Member functions-------" << std::endl;
    pC4->f();
    pC4->g();
    pC4->h4();

    delete pC4;
    pC4 = 0;
    
    std::cout << "----------Leaving test_4()-----------" << std::endl;

}



