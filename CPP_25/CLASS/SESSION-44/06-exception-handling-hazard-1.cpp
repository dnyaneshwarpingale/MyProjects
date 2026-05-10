#include <iostream>
#include <stdexcept>

class Date
{
    private:
        int day, month, year;
    public:
        Date(int dd, int mm, int yy) : day(dd),month(mm),year(yy){}

        int get_month()const
        {
            return month;
        }

        void set_month(int new_month)
        {
            month = new_month;
        }

        ~Date()
        {
            std::cout << "In Date::~Date()" << std::endl;

        }
};

class DatePtr
{
    private:
        Date* ptrToDate;
    public:
        DatePtr(int dd, int mm, int yy)
        {
            ptrToDate = new Date(dd,mm,yy);
        }
        
        Date* operator->()
        {
            return ptrToDate;
        }

        ~DatePtr()
        {
            std::cout << "-------Entered DatePtr::~DatePtr()-------" << std::endl;
            delete ptrToDate;
            std::cout << "----------Leaving DatePtr::~DatePtr()------" << std::endl;

        }

};

void f1();
void f2();
void g();

int main()
{
    try
    {
        f1();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return(0);
}

void f1()
{
    std::cout << "------Entered f1()------" << std::endl;
    DatePtr myDatePtr(1,3,2026);
    std::cout << "Month:" << myDatePtr->get_month() << std::endl;
    myDatePtr->set_month(5);
    std::cout << "Month:" << myDatePtr->get_month() << std::endl;
    f2();
    std::cout << "--------Leaving f1()-----"<< std::endl;
}

void f2()
{
    std::cout << "-------Entered f2()-------" << std::endl;
    Date* pDate = new Date(1,1,1970);
    g();
    delete pDate;
    pDate = 0;
    std::cout << "------Leaving f2()-------"<< std::endl;
}

void g()
{
    std::cout <<"---------Entered g()----" << std::endl;
    throw std::runtime_error("some error from g()");
    std::cout << "--------Leaving g()------" << std::endl;
    
}