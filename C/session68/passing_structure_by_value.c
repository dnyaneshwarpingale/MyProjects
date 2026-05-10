#include <stdio.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void show_date(struct Date date_var); 

int main(void)
{
    struct Date myDate; 

    myDate.day = 1; 
    myDate.month = 2; 
    myDate.year = 2024; 

    show_date(myDate); 

    return (0); 
}

void show_date(struct Date date_var)
{
    printf("%d-%d-%d\n", date_var.day, date_var.month, date_var.year); 
}

