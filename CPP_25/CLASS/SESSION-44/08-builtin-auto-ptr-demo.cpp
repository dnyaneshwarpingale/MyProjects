#include <iostream>
#include <memory>

class Date
{
    private:
        int day, month, year;
    public:
        Date(int dd, int mm, int yy) : day(dd), month(mm),year(yy){}

        int get_month() const
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

void f();

int main()
{
    std::cout << __cplusplus << std::endl;
    f();
    return 0;
}

void f()
{
    std::auto_ptr<Date> datePtr(new Date(1,3,2026));
    std::cout << "Month:"<< datePtr->get_month() << std::endl;
}
