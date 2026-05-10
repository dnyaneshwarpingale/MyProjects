#include <stdio.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

int main(void)
{
    char* ptr_to_char = 0;  // sizeof(char) == 1 
    short* ptr_to_short = 0; // sizeof(short) == 2 
    int* ptr_to_int = 0; // sizeof(int) == 4 
    long* ptr_to_long = 0; // sizeof(long) == 4 
    long long* ptr_to_long_long = 0; // sizeof(long long) == 4 

    float* ptr_to_float = 0;    // sizeof(float) == 4 
    double* ptr_to_double = 0;  // sizeof(double) == 8

    struct Date* ptr_to_date_struct = 0; // sizeof(struct Date)==12

    printf("ptr_to_char + 1 = %llu\n", (unsigned long long)(ptr_to_char + 1));  // 1 
    printf("ptr_to_short + 1 = %llu\n", (unsigned long long)(ptr_to_short + 1));  // 2       
    printf("ptr_to_int + 1 = %llu\n", (unsigned long long)(ptr_to_int + 1)); // 4
    printf("ptr_to_long + 1 = %llu\n", (unsigned long long)(ptr_to_long + 1)); // 4          
    printf("ptr_to_long_long + 1 = %llu\n", (unsigned long long)(ptr_to_long_long + 1));  // 8         
    printf("ptr_to_float + 1 = %llu\n", (unsigned long long)(ptr_to_float + 1));   // 4        
    printf("ptr_to_double + 1 = %llu\n", (unsigned long long)(ptr_to_double + 1));   // 8        
    printf("ptr_to_date_struct + 1 = %llu\n", (unsigned long long)(ptr_to_date_struct + 1));  // 12              

    return (0); 
}

// General formula: 
// T* ptr; 
// ptr is a pointer to type T 
// Let x be an address in ptr. 
// Let k be any integer. 

// ptr + k is evaluated as follows 
// address in ptr + k * sizeof(T)
// x + k * sizeof(T)


