#include <iostream>

struct Date_1
{
    int day;
    int month;
    int year;

};

class Date_2
{
    private:
    int day;
    int month;
    int year;

};

int main(void)
{
    struct Date_1 myDate_1;
    Date_2 myDate_2;

    myDate_1.month =10;//ok
    myDate_2.month =10; //error

    return 0;
    
}