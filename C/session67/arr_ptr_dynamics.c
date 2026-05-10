#include <stdio.h> 

#define N 8 

int a[N] = {100, 200, 300, 400, 500, 600, 700, 800}; 
int* ptr = &a[0]; 
int i; 

int main(void)
{
    i = 0; 
    while(i < N)
    {
        printf("-----INDEX %d-----\n", i); 
        puts("ADDRESS:"); 
        printf("&a[%d]\t==\t%llu\n", i, (unsigned long long)&a[i]); 
        printf("ptr + %d\t==\t%llu\n", i, (unsigned long long)(ptr+i)); 
        puts("VALUE:"); 
        printf("a[%d]\t==\t%d\n", i, a[i]); 
        printf("*(ptr+%d)==\t%d\n", i, *(ptr+i)); 

        i = i + 1; 
    }

    return (0); 
}