#include<iostream>

class Date
{
    friend void test(void);  // DECLARATION
    private:
        int day, month, year;
    
    public:
        Date(int dd, int mm, int yy) : day(dd),month(mm),year(yy)
        {

        }
};

void test(void);

int main(void)
{
    Date myDate_main(7,12,2025);
    test();

    // myDate_main.day = 8; //CTE : private variable not accessible

    return (0);
}

void test(void)
{
    Date myDate_test(7,12,2025);

    // Even though test function is a function implemented outside
    // class Date, infact it is a global C Like function , it is 
    // declared to be a freind of class Date.

    // And that declaration allows test() function to access private 
    // members (data or function ) of all objects of Date that are
    // visible

    myDate_test.day = 8;
    myDate_test.month = 10;
    myDate_test.year = 2024;
}