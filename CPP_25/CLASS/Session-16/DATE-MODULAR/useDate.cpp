#include "Date.hpp"

void test_date(void);

int main(void)
{
    test_date();
    return EXIT_SUCCESS;

}

void test_date(void)
{
    Date myDate;

    std::cout << "Showing myDate:";
    myDate.show();

    Date today(15, 11, 2025);
    std::cout << "showing today:";
    today.show();

    //---------------Invalid initilizers-----------
    Date myDateOne(34,2,1900);
    Date myDateTwo(2,56,2025);
    Date myDateThree(31,9,2025);
    Date myDateFour(29,2,2025);

    std::cout << "showing myDateOne, myDateTwo, myDateThree, myDateFour respectively" << std::endl;
    // all are 1/1/1970
    myDateOne.show();
    myDateTwo.show();
    myDateThree.show();
    myDateFour.show();

    Date testDate(15, 11,2025);

    int day = testDate.get_day();
    int month = testDate.get_month();
    int year = testDate.get_year();

    std::cout << "Showing testDate:" << day << "/" << month << "/" << year << std::endl;

    testDate.set_date(24);
    testDate.set_month(3);
    testDate.set_year(2026);

    std::cout << "Showing modified testDate:";
    testDate.show();

    Date* pDate =new Date(25,11,2025);
    std::cout << "Showing pDate";
    pDate->show();

    day = pDate->get_day();
    month = pDate -> get_month();
    year = pDate -> get_year();

    std::cout << "Showing pDate by obtaining values from getters():" << day << "/" <<month <<"/" <<year<< std::endl; 

    pDate->set_date(26);
    pDate-> set_month(3);
    pDate->set_year(2026);

    std::cout<<"showing modified pDate:";
    pDate->show();

    const Date* cpDate =new Date(15, 11, 2025);
    //only getters can be called from cpDate

    day = cpDate->get_day();
    month =cpDate->get_month();
    year = cpDate-> get_year();
    std::cout<< " showing cpDate by otaining values from getters: "<< day << "/" << month << "/" << year<< std::endl;
    std::cout<< "Showing cpDate by show() function:";
    cpDate->show();

    //cpDate ->set_day(24);   //CTE
    //cpDate ->set_month(3);    //CTE
    //cpDate ->set_year(2026);   //CTE

    delete cpDate;
    cpDate = 0;

}