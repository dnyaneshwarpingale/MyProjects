#include<iostream>

class Date
{
    friend std::ostream& operator<<(std::ostream& os, const Date& dateObject);
    friend std::istream& operator>>(std::istream& is, Date& dateObject);
    private:
        int day, month, year;

    public:
        Date()
        {

        }

        Date(int _day, int _month, int _year):day(_day),month(_month),year(_year)
        {

        }

        void show() const
        {
            std::cout<< day << "/" << month << "/" << year << std::endl;
        }
};

std::ostream& operator<<(std::ostream& os, const Date& dateObject)
{
    os << dateObject.day << "/" << dateObject.month << "/" << dateObject.year << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is , Date& dateObject)
{
    std::cout << "Enter valid value for day:";
    is >> dateObject.day;
    std::cout << "Enter valid value for month:";
    is >> dateObject.month;
    std::cout << "Enter valid value for year:";
    is >> dateObject.year;

    return is;
}

class Employee
{

};

std::ostream& operator<<(std::ostream& os, const Employee& employeeObject)
{
    return os;
}

void testOne(void);
void testTwo(void);

int main(void)
{
    testOne();
    testTwo();

    return EXIT_SUCCESS;
}

void testOne(void)
{
    Date myDate1(13,12,2025);
    Date myDate2(14,12,2025);

    std::cout << "----------Entered testOne()----------" << std::endl;
    std::cout << "myDate1:" << myDate1 << std::endl
                <<"myDate2:" << myDate2 << std::endl;
    std::cout << "-------leaving testOne()------"<< std::endl;
}

void testTwo(void)
{
    Date myDate;
    Date myDate1, myDate2;
    std::cout << "--------Entered testTwo()-------" << std::endl;
    std::cin >> myDate; // operator>>(std::cin, myDate)

    std::cout << "-----------Testing chaining of cin operator---------" <<std::endl;
    std::cin >> myDate >> myDate2;
    std::cout << "----------Testing chaining of cin operator End-----" << std::endl;

    std::cout << "myDate: "<< myDate << std::endl;
    std::cout << "myDate1: " << myDate1 << std::endl;
    std::cout << "myDate2:" << myDate2 << std::endl;
    std::cout << "--------Leaving testTwo()---------" << std::endl;

}



