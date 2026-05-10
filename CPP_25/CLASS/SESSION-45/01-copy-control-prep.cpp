#include <iostream>

class C 
{
    private:
        int a;
        char b;
        float f;
    public:
        C(int _a, char _b, float _f) : a(_a), b(_b), f(_f)
        {

        }

        // If we do not implement the following constructor compiler will 
        // generate one for us -> known as synthesized copy constructor
        C(const C& other)
        {
            // New object to be initialized is pointed by this pointer
            // Existing object by which to initialize is referred by other
            std:: cout << "--------Entered Copy Constructor-------" << std::endl;
            this->a = other.a;
            this->b = other.b;
            this->f = other.f;
            std::cout << "-----------Leaving Copy Constructor--------" << std::endl;

        }
        // If we do not implement following operator overloading member function
        // then the compiler will generate one for us -> known as synthesized copy
        // assignment operator

        C& operator=(const C& other)
        {
            // An LHS object in the assignment statement is pointed by this
            // An RHS object in the assignement is reffered by other.
            std::cout << "-----------Entered Copy Assignement Operator-----"<< std::endl;
            this->a = other.a;
            this->b = other.b;
            this->f = other.f;
            std::cout << "---Leaving Copy Assignment Operator-------" << std::endl;

            return *this;
        }
} ; 

void test();

int main()
{
    test();
    return 0;

}

void test()
{
    C c1(10, 'A', 1.1f);

    std::cout << "main():About to initilaize new object of class C by C by existing object of class C"
        << std::endl;

    C c2(c1); // New object of class C(viz. c2) is being initialized by an existing
              // object of class C(viz. c1)

    C c3(20, 'B', 2.2f);
    
    std::cout << "main(): About to assign an existing object of class C by another existing obect of class C" << std::endl;
    c3 = c2; // An existing object of class C(viz.c3) is being initialized by another 
            // existing object of class c(viz.c2)
}



