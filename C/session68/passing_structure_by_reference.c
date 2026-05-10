#include <stdio.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void show_date(struct Date* pDate); 

int main(void)
{
    struct Date myDate; 

    myDate.day = 1; 
    myDate.month = 2; 
    myDate.year = 2024; 

    printf("BEFORE:%d-%d-%d\n", myDate.day, myDate.month, myDate.year); 
    show_date(&myDate); 
    printf("AFTER:%d-%d-%d\n", myDate.day, myDate.month, myDate.year); 

    return (0); 
}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    pDate->day = 3; 
    pDate->month = 6; 
    pDate->year = 1999; 
}

