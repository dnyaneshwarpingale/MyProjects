#include <stdio.h> 

void fill_array(int* p_start_arr, int N); 
void show_array(int* p_start_arr, int N); 

int main(void)
{
    // all five integers in array are initialized to 0
    int a[5] = {0, 0, 0, 0, 0}; 

    fill_array(&a[0], 5); 
    show_array(&a[0], 5); 

    return (0); 
}

void fill_array(int* p_start_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
        *(p_start_arr + i) = (i+1) * 100; 
}

void show_array(int* p_start_arr, int N)
{
    int i; 
    int element_val; 

    for(i = 0; i < N; ++i)
    {
        element_val = *(p_start_arr + i); 
        printf("element_val at index %d = %d\n", i, element_val); 
    }
}

// type(a) == type(&a[0])

// type(a) == int []

// BEEJ's guide to networking 

// Unix Network Programming vol 1 by W. Richard Stevens Edition 3 