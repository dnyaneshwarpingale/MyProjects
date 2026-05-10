#include <iostream>
class Date
{

private:
    int day;
    int month;
    int year;

public:
    Date(int init_day, int init_month, int init_year):day(init_day), month(init_month), year(init_year)
    {

    }

    int get_day()
    {
        return this->day;
    }

    int get_month()
    {
        return this->month;
    }

    int get_year()
    {
        return this->year;
    }

    void set_day(int new_day)
    {
        this->day = new_day;
    }

    void set_month(int new_month)
    {
        this->month=new_month;

    }

    void set_year(int new_year)
    {
        this->year=new_year;
    }

    void show()
    {
        std::cout << day << "/"<< month << "/" << year << std::endl;
    }


};

int main(void)
{
    Date myDate_1(28, 9, 2025);
    int day = myDate_1.get_day();
    int month = myDate_1.get_month();
    int year = myDate_1.get_year();

    std::cout << "Testing getters():" << day << "/" << month << "/" << year << std::endl;
    myDate_1.set_day(2);
    myDate_1.set_month(10);
    myDate_1.set_year(2025);

    std::cout << "Testing setters and show function"<< std::endl;
    myDate_1.show();
    return 0;
}
