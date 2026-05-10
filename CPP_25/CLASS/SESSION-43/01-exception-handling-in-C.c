#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

double my_sqrt(int x);
void helper_1(int);
void helper_2(int);
void helper_3(int);
void helper_4(int);

jmp_buf my_buff;

int main(void)
{
    int arr[] = {100, 200, -300, 400, 500, -600, -700, 800};
    int i;
    int ret_val;
    
    ret_val = setjmp(my_buff);
    if(ret_val == 0)
        puts("JMP POINT IS SET");
    else if(ret_val == 1) 
    {
        puts("main():Sorry, I sent a negative number to my_sqrt()");
        goto next_iteration;
    }

    i =0;
    while (i<8)
    {
        double ans;
        ans = my_sqrt(arr[i]);
        printf("ans = %lf\n",ans);
    next_iteration:
        i = i+1;
    }

    return (0);
}

double my_sqrt(int x)
{
    puts("my_sqrt():Befor helper_1()");
    helper_1(x);
    puts("my_sqrt():After helper_1()");
    return 0.0;
}

void helper_1(int x)
{
    puts("helper_1():Befor helper_2()");
    helper_2(x);
    puts("helper_1():After helper_2()");
}

void helper_2(int x)
{
    puts("helper_2():Befor helper_3()");
    helper_3(x);
    puts("helper_2():After helper_3()");
}

void helper_3(int x)
{
    puts("helper_3():Befor helper_4()");
    helper_4(x);
    puts("helper_3():After helper_4()");
}

void helper_1(int x)
{
    puts("helper_4():Befor Error Detection");
    if(x < 0)
    {
        longjmp(my_buff,1);
    }
    puts("helper_4():After After Error Detection");
}