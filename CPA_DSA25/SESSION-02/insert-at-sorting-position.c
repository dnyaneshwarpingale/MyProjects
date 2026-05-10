#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    // Define an array of 5 elements
    int N = 5;
    int arr[5] = {50, 60,70,80,10};

    // Index variable for looping
    int tmp;
    int i ;
    // Display array as it is
    puts("showing array before insert -at sorting()");
    i = 0;
    while(i<N)
    {
        printf("arr[%d]:%d",i,arr[i]);
        i = i + 1;

    }

    // Insert at sorting position Logic
    tmp = arr[N-1];
    i = N-2;

    while(i >= 0)
    {
        arr[i + 1] = arr[i];
        i = i-1;
    }
    arr[i+1] = tmp;

  exit(0);
}